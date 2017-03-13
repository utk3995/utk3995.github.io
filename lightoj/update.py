import numpy as np
import os
import mechanize
from shutil import copyfile


br = mechanize.Browser()
br.set_handle_robots(False)
br.open("http://www.lightoj.com/login_main.php")	   #Url that contains signin form
br.select_form(nr=0)
br['myuserid'] = "icm2014003@iiita.ac.in"	#see what is the name of txt input in form
br['mypassword'] = '3codingpassword4#'
result = br.submit().read()
if (result == "<script>location.href='login_success.php'</script>"):
    print "Login Success"
else:
    print "Login Failure"


indexfile = open('./index.html','w')
indexfile.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">\n')
indexfile.write('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">\n')
indexfile.write('\t<title>List of Problems</title>\n')
indexfile.write('<body style="background: white; font-family: Helvetica">\n')
indexfile.write('<h1> List of solved problems </h1><br/>\n')

count = 1

for file in os.listdir("./source_cpp/"):
	if file.endswith(".cpp"):
		copyfile('./source_cpp/'+file,'./input.cpp')
		os.system("./convertor")
		copyfile('./output.cpp','./converted_cpp/'+file)
		os.system("rm output.cpp")
		os.system("rm input.cpp")


for file in os.listdir("./converted_cpp/"):
	if file.endswith(".cpp"):
		words = file.split(".")
		quesitonCode = words[0]
		print quesitonCode
		url = br.open("http://lightoj.com/volume_showproblem.php?problem="+str(quesitonCode))
		returnPage = url.read() 
		returnHtml = open('temphtml.html','w')
		returnHtml.write(returnPage)
		returnHtml.close()
		os.system("./probStatementExtractor")
		pageTitle = br.title()
		words = pageTitle.split("::")
		questionTitle = words[1]
		words = questionTitle.split("-")
		problemName = words[1]
		probStatementFile = open('probstatement.txt','r')
		problemStatement = probStatementFile.read()

		indexfile.write(str(count)+'. ')
		count = count + 1
		indexfile.write('<a href=files/'+str(quesitonCode)+'.html>'+questionTitle+'</a><br>\n')

		outfile = open('./files/'+quesitonCode+'.html','w')
		infile  = open('./converted_cpp/'+quesitonCode+'.cpp','r')

		outfile.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">\n')
		outfile.write('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">\n')
		outfile.write('<head>\n')
		outfile.write('\t<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />\n')
		outfile.write('\t<title>'+questionTitle+'</title>\n')
		outfile.write('\t<script type="text/javascript" src="../scripts/shCore.js"></script>\n')
		outfile.write('\t<script type="text/javascript" src="../scripts/shBrushCpp.js"></script>\n')
		outfile.write('\t<link type="text/css" rel="stylesheet" href="../styles/shCoreDefault.css"/>\n')
		outfile.write('\t<script type="text/javascript">SyntaxHighlighter.all();</script>\n')
		outfile.write('</head>\n')
		outfile.write('<body style="background: white; font-family: Helvetica">\n')
		outfile.write('<h1>Question Code : '+str(quesitonCode)+'.cpp</h1>\n')
		outfile.write('<h1>Problem Name : '+problemName+'</h1><br/>\n')
		outfile.write('<h3>Problem Statement : </h3><br/>\n')
		outfile.write(problemStatement+'<br/>');
		outfile.write('<h3>Code : </h3><br/>\n')
		outfile.write('<pre class="brush: cpp;">\n')
		#file input
		input_str = infile.read()
		outfile.write(input_str);
		#file input
		outfile.write('</body>\n')
		outfile.write('</pre>\n')
		outfile.write('</html>\n')
		outfile.close()
		os.system("rm probstatement.txt")
		os.system("rm temphtml.html")

indexfile.write('</body>\n')
indexfile.write('</html>\n')
indexfile.close()