So what should I define in the header file vs the cpp file, and what inside the class definition vs outside?
===

You might be tempted to put all of your member function definitions into the header file, inside the class. While this will compile, there are a couple of downsides to doing so. First, as mentioned above, this clutters up your class definition. Second, if you change anything about the code in the header, then you’ll need to recompile every file that includes that header. This can have a ripple effect, where one minor change causes the entire program to need to recompile (which can be slow). If you change the code in a .cpp file, only that .cpp file needs to be recompiled!

Therefore, we recommend the following:

- For classes used in only one file that aren’t generally reusable, define them directly in the single .cpp file they’re used in.
- For classes used in multiple files, or intended for general reuse, define them in a .h file that has the same name as the class.
- Trivial member functions (trivial constructors or destructors, access functions, etc…) can be defined inside the class.
- Non-trivial member functions should be defined in a .cpp file that has the same name as the class.

(read more: https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)