#! /usr/bin/env python3
# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

import os.path
import re
import sys

# -----------------------------------------------------------------------------

def raise__illegal_section(filepath, line_number):
    raise Exception( 'Illegal SECTION in input file '
                     + '"' + filepath + '", '
                     + 'line ' + str(line_number) )

def gen_section(filepath, line_comment_begin):
    section_re = line_comment_begin + r'\s*SECTION'
    ignore_re  = r'\s+IGNORE'
    begin_re   = r'\s+BEGIN'
    end_re     = r'\s+END'
    pause_re   = r'\s+PAUSE'
    resume_re  = r'\s+RESUME'
    indent_re  = r'\s+INDENT'
    name_re    = r'\s+([\w-]+)'

    section = re.compile( section_re )
    ignore  = re.compile( section_re + ignore_re )
    begin   = re.compile( section_re + begin_re + name_re )
    end     = re.compile( section_re + end_re + name_re )
    pause   = re.compile( section_re + pause_re + name_re )
    resume  = re.compile( section_re + resume_re + name_re )
    indent  = re.compile( section_re + indent_re + name_re )

    sections_lines  = { 'all':'' }  # the lines of text, for every section
    sections_open   = { 'all' }     # sections currently being processed
    sections_indent = { 'all':0 }   # number of initial characters to discard

    f = open(filepath)

    line_number = 0;
    for line in f:
        line_number += 1
        if ignore.search(line):
            pass
        elif begin.search(line):
            name = begin.search(line).group(1)
            sections_lines[name] = ''
            sections_open.add(name)
            sections_indent[name] = re.search( r'\S', line ).start()
        elif end.search(line):
            name = end.search(line).group(1)
            if name in sections_open:
                sections_open.remove(name)
            else:
                raise__illegal_section(filepath, line_number)
        elif pause.search(line):
            name = pause.search(line).group(1)
            if name in sections_open:
                sections_open.remove(name)
            else:
                raise__illegal_section(filepath, line_number)
        elif resume.search(line):
            name = resume.search(line).group(1)
            sections_open.add(name)
        elif indent.search(line):
            name = indent.search(line).group(1)
            sections_indent[name] = re.search( r'\S', line ).start()
        else:
            if section.search(line):
                raise__illegal_section(filepath, line_number)
            for name in sections_open:
                sections_lines[name] += line[sections_indent[name]:] or '\n'

    f.close()

    for s in sections_lines:
        newpath = filepath + '.gen.section.' + s
        f = open(newpath,'w')
        f.write(sections_lines[s])
        f.close()

# -----------------------------------------------------------------------------

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print( 'USAGE: ' + sys.argv[0] + ' <filepath> <line_comment_begin>' )
        sys.exit(1)

    gen_section(sys.argv[1], sys.argv[2])

