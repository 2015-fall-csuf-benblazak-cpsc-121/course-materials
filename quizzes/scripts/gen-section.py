#! /usr/bin/env python3
# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

import os.path
import sys

def gen_section(filepath, line_comment_begin):
    begin = line_comment_begin + ' SECTION BEGIN '
    end = line_comment_begin + ' SECTION END '

    sections_lines = { '':'' }
    sections_open = { '' }
    sections_strip = { '':0 }

    f = open(filepath)

    for line in f:
        if begin in line:
            name = line[line.find(begin)+len(begin):-1].replace(' ','-')
            sections_lines[name] = ''
            sections_open.add(name)
            sections_strip[name] = line.find(begin)
        elif end in line:
            name = line[line.find(end)+len(end):-1].replace(' ','-')
            sections_open.remove(name)
        else:
            for name in sections_open:
                sections_lines[name] += line[sections_strip[name]:]

    f.close()

    for s in sections_lines:
        newpath = filepath + '.gen.section' + ('-' if s else '') + s
        f = open(newpath,'w')
        f.write(sections_lines[s])
        f.close()


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print( 'USAGE: ' + sys.argv[0] + ' <filepath> <line_comment_begin>' )
        sys.exit(1)

    gen_section(sys.argv[1], sys.argv[2])

