# Parse -c or -h
# If -c, generate the following:
# <license>
# \n
# #include <[lowercase_name].h>
# \n\n\n
# Write to ../src/[lowercase_name].c
# If -h, generate the following:
# #ifndef [UPPERCASE_NAME]_H
# \t#define [UPPERCASE_NAME]_H
# \n\n\n
# #endif //[UPPERCASE_NAME]_H
# Write to ../src/include/[lowercase_name].h
# If no args, do both.

#!/bin/python3

import sys

def usage():
    print('./autogen.py <filename>')

def autogen():
    if len(sys.argv) < 2:
        usage()
        sys.exit(1)

    c_path = f'../src/{sys.argv[1].lower()}.c'
    h_path = f'../src/include/{sys.argv[1].lower()}.h'
    c_contents = f"""/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <{sys.argv[1].lower()}.h>



"""
    
    h_contents = f"""/*
Copyright 2025 Benjamin Fryxell
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef {sys.argv[1].upper()}_H
    #define {sys.argv[1].upper()}_H


#endif //{sys.argv[1].upper()}_H
"""
    with open(c_path, '+w') as cf:
        cf.write(c_contents)
    with open(h_path, '+w') as hf:
        hf.write(h_contents)

if __name__ == '__main__':
    autogen()
