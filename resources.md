# Resources

## History and Culture

- [The Bjarne Stroustrup homepage]
  (http://www.stroustrup.com)  
  Because Bjarne Stroustrup invented C++, and knows quite a bit about it

- [So what *did* Alan Kay really mean by the term “object-oriented”?]
  (http://programmers.stackexchange.com/a/58732)  
  Alan Kay on the definition of "object-oriented programming"

- [The Deep Insights of Alan Kay]
  (http://mythz.servicestack.net/blog/2013/02/27/the-deep-insights-of-alan-kay/)  
  A very good collection of quotes and such.


## Technical Reference

- [The C++ Programming Language]
  (https://isocpp.org)  
  Links to the C++ standard and the C++ Super-FAQ

- [cplusplus.com]
  (http://www.cplusplus.com)  
  Good page for general C++ information, tutorials, reference, etc.

- [C++ Reference]
  (http://en.cppreference.com/w/)  
  Probably slightly better than [cplusplus.com] (http://www.cplusplus.com) as a
  technical reference, though [cplusplus.com] (http://www.cplusplus.com) does
  tend to have better examples

- [cdecl]
  (http://cdecl.org)  
  Helpful with understanding C style type declarations

- [Sutter’s M / GotW]
  (http://herbsutter.com/gotw/)  
  Looks like a lot of good articles on C++ topics.

- [EmbeddedGurus]
  (http://embeddedgurus.com)  
  Great articles on topics related to embedded programming.


## Technical Notes

- [Is "inline" implicit in C++ member functions defined in class definition]
  (http://stackoverflow.com/a/9192199)  
  About the `inline` keyword, and the ODR (One Definition Rule)

- [Are pointers and arrays equivalent in C?]
  (http://eli.thegreenplace.net/2009/10/21/are-pointers-and-arrays-equivalent-in-c)  
  Short answer: no; but you should (*always*) try to understand why

- [Reading files line by line in C++ using ifstream: dealing correctly with
  badbit, failbit, eofbit, and perror()]
  (https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/)

- [Doing it wrong: getters and setters]
  (http://typicalprogrammer.com/doing-it-wrong-getters-and-setters/)  
  Getters and setters are very common (or at least very commonly known) so you
  should understand them thoroughly.  And then, according to this blog, you
  shouldn't use them.  And his position makes a lot of sense if you listen to
  Alan Kay a bit, and really take in the idea that OOP is all about passing
  message to objects, rather than about encapsulation or abstract data types or
  anything else.

- [typedef struct vs struct definitions]
  (http://stackoverflow.com/a/1675446)  
  Identifier lookup is different for `struct`s in C and C++.

- [Private and Protected Members : C++]
  (http://stackoverflow.com/questions/224966/private-and-protected-members-c)

- [Conversion from `int**` to `const int**`]
  (http://stackoverflow.com/questions/16390294/conversion-from-int-to-const-int)  
  From [one of the answers](http://stackoverflow.com/a/16390381):

  > You can only add const qualification in a conversion between similiar
  > pointer types if you add const at all levels from the first difference in
  > cv qualification and up.
  >
  > So, you can convert `int**` to `int const* const*`, but not to `int const*
  > *`.

- [Default class inheritance access]
  (http://stackoverflow.com/a/3811441)

- [What is the difference between new/delete and malloc/free?]
  (http://stackoverflow.com/a/240308)

- [What are Aggregates and PODs and how/why are they special?]
  (http://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special)


## Tutorials

- [GitHub Help / Bootcamp / Fork A Repo]
  (https://help.github.com/articles/fork-a-repo/)

- [GitHub Help / Collaborating / Using pull requests]
  (https://help.github.com/articles/using-pull-requests)


## Administrative

- [University Catalog: Computer Science, B.S.]
  (http://catalog.fullerton.edu/preview_program.php?catoid=2&poid=537)

- [ECS Wiki]
  (https://wiki.ecs.fullerton.edu)

- [CSUF Academic Calendar]
  (http://apps.fullerton.edu/AcademicCalendar/)

- [CSUF Finals Schedule]
  (http://www.fullerton.edu/admissions/currentstudent/finalexaminations.asp)


## Software

- [Linux Mint]
  (http://www.linuxmint.com/download.php)  
  Because Linux is better, freer, and easier (especially for programming, once
  you get used to it) than Windows.  I recommend the Cinnamon version.

- [Visual Studio Community]
  (https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx)  
  A free (and I think fully featured) version of Visual Studio

- [Microsoft DreamSpark]
  (https://www.dreamspark.com/Student/)  
  Free Microsoft software (for students, at least).  Though, I'm not sure why
  that's helpful.  It used to be more so.

- [CSUF Student Software]
  (http://www.fullerton.edu/IT/students/software/)  
  Which you for sure already know about :)


-------------------------------------------------------------------------------
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)]
(http://creativecommons.org/licenses/by/4.0/)  
Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>  
This work is licensed under a [Creative Commons Attribution 4.0 International
License] (http://creativecommons.org/licenses/by/4.0/)  
Project located at <https://github.com/2015-fall-csuf-benblazak-cpsc-121>

