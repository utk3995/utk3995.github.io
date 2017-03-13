import numpy as np
import os
from shutil import copyfile

indexfile = open('./index.html','w')
indexfile.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">\n')
indexfile.write('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">\n')
indexfile.write('\t<title>List of Problems</title>\n')
indexfile.write('<body style="background: white; font-family: Helvetica">\n')
indexfile.write('<h1> List of problems </h1><br/><br/>\n')

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
		
		indexfile.write(str(count)+'.')
		count = count + 1
		indexfile.write('<a href=files/'+str(quesitonCode)+'.html>'+str(quesitonCode)+'</a><br>\n')

		outfile = open('./files/'+quesitonCode+'.html','w')
		infile  = open('./converted_cpp/'+quesitonCode+'.cpp','r')

		outfile.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">\n')
		outfile.write('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">\n')
		outfile.write('<head>\n')
		outfile.write('\t<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />\n')
		outfile.write('\t<title>'+str(quesitonCode)+'</title>\n')
		outfile.write('\t<script type="text/javascript" src="../scripts/shCore.js"></script>\n')
		outfile.write('\t<script type="text/javascript" src="../scripts/shBrushCpp.js"></script>\n')
		outfile.write('\t<link type="text/css" rel="stylesheet" href="../styles/shCoreDefault.css"/>\n')
		outfile.write('\t<script type="text/javascript">SyntaxHighlighter.all();</script>\n')
		outfile.write('</head>\n')
		outfile.write('<body style="background: white; font-family: Helvetica">\n')
		outfile.write('<h1>Question Code : '+str(quesitonCode)+'.cpp</h1>\n')
		outfile.write('<pre class="brush: cpp;">\n')
		#file input
		input_str = infile.read()
		outfile.write(input_str);
		#file input
		outfile.write('</body>\n')
		outfile.write('</pre>\n')
		outfile.write('</html>\n')
		outfile.close()
indexfile.write('</body>\n')
indexfile.write('</html>\n')
indexfile.close()