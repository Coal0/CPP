learncpp.com quizzes
====================

`learncpp.com <http://www.learncpp.com>`_ is a beginner-oriented tutorial to modern C++, available for free. This repository contains all kinds of quizzes taken from the website. Some quiz descriptions / requirements were modified to better fit a certain skill level, to be more challenging, or to take advantage of modern (C++11 / C++14) features. Each quiz will get its own directory. The naming conventions for quizzes are:

.. code:: 

  (chapter).(section)[subsection]_(quiz)[quizSubsection]
  
For example, for `chapter 2, section 6 <http://www.learncpp.com/cpp-tutorial/26-boolean-values/>`_, quiz 1:

.. code::

  c2.6_1

... for `chapter 5, comprehensive quiz <http://www.learncpp.com/cpp-tutorial/5-x-chapter-5-comprehensive-quiz/>`_, quiz 2a:

.. code::

  5.x_2a
  
*Note: almost all chapters end with a 'comprehensive quiz' section. The symbol for that section is 'x'.*

... for `chapter 1, section 4c <http://www.learncpp.com/cpp-tutorial/14c-keywords-and-naming-identifiers/>`_, quiz 1:

.. code::

  1.4c_1

There is no default format for directories, however, in 99% of cases, the format will be as follows:

.. code::

  name/
    quiz.txt
    solution.txt
    main.cpp
    [other C++ files, data files, ...]

Under most circumstances, compilation should be as simple as:

.. code:: bash

  g++ -std=c++14 -Wall -Werror -Wextra -Wpedantic -o main main.cpp

Replace ``g++`` with your compiler of choice.
Some quizzes will require custom compilation options. Those quizzes should be accompanied with a 'compilation.txt' file, which explains how to compile and run the code.
