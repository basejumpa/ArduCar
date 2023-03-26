Play with GitHub Flow in Embedded Context
#########################################


Repository health
*****************

Branch :code:`main`: |health_main|

.. |health_main| image::https://github.com/basejumpa/arduCar/actions/workflows/main.yml/badge.svg?branch=main

Contributor's Guide
*******************

Initial setup of repository
===========================

#. **Fork** this repository from the https://github.com/basejumpa/arduCar into your personal space on the server using the GitHub web interface.
#. **Clone** your fork somewhere onto your local harddrive. Your fork is the remote with name :code:`origin`
#. **Configure** this repository as the upstream repository :code:`git remote add upstream https://github.com/basejumpa/arduCar.git`

For each contribution do
========================

#. Get latest greatest: :code:`git fetch upstream`
#. Create your **local feature branch**: :code:`git checkout -b feature/my-cool-feature upstream/develop`
#. Hint: Track upstream with your tracking branch: :code:`git branch -u upstream/develop`
#. Create a changes, save them, add them and commit them: :code:`... ; git add ... ; git commit ...`
#. **Regularily update** your local repository and your fork: :code:`git fetch upstream ; git merge ...`
#. Work on your files in a test driven way. While coding run regularily the unittests of all modules you're working on. Execute them either in the **git shell** with :code:`./makew unittest` or from within your IDE. Read below to learn how to reduce the build scope to specific units.
#. When your stuff is mature enough for the first review + test, then ... *create pull request- using the GitHub web interface.

Installation of the toolchain
=============================

The installation is done within the first build on your machine.
Because of this the first build takes longer.
The installation is done within the git installation which is part of your SmartGit folder. It is just a copy process, so your Windows System doesn't get polluted.

Changing the scope of build:
============================

Edit the file :code:`makew_settings.mk` to change the scope of any target.

The defaults are::

    FLAVORS=M_a
    UNITS=.+
    DEVICE=1


The values of both variables :code:`FLAVORS` and :code:`UNITS` are https://en.wikipedia.org/wiki/Regular_expression[*regular expressions*].


The defaults mean do the target ...

- for flavor :code:`M_a` only and over
- all existing units.


Examples how to restrict it::

    FLAVORS=.+
    UNITS=A1
    DEVICE=1

That means loop over all existing flavors :code:`M_a` and only unit :code:`A1`.


Some more complex example::

    FLAVORS=M_.+
    UNITS=[AD][13-5]
    DEVICE=1

That means apply the target over all flavors of customer :code:`M` and over the units :code:`A1`A3`, :code:`A4`, :code:`A5`, :code:`D1`, :code:`D3`, :code:`D4` and :code:`D5`.
