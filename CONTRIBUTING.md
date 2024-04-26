# Contributing Guidelines

1. All Code should follow Google's Style Guide (Some things I don't know and dont' care to remember, i'm specifically referring to using 2 spaces for code instead of 4, and similar rules.)
2. All Code should be clear, concise, and documented. All functions need doxygen, and if something appears ambigious, such as a for loop without a clear purpose, it should have comments.
   1. Extending the above, everything should have clear variable names. This means Labeling Motors A,B,C..., and naming motors MOTOR_A-DRIVETRAIN, or MOTOR_G-LAUNCHER.
   2. Loops should be avoided in main functions, excluding while loops to keep a function running. This means no looping over data inside of opcontrol()
   3. Following Initial Repository Setup, Everything  should be implemented in seperate branches and Pull Requested into the main branch. Each branch should be as specific as possible, and should be minimally intrusive.
      a. This repository will contain the following branches: Stable (Representing full tested and working competition ready code. Should be tested fully either with a competition controller brain or field.jerry.io), Working [master] (Representing active development, accepts merges from feat/ and issue/ and hotfix/), feat/ preflixed branches (implementing new features such as new autonomouses), issue/ preflixed branches, (fixing existing bugs in older code), and hotfix (Used in the days leading up to competitons, or at competitions, if there is a plauging bug present in the stable code. Always base from and merge into Stable). Follow the guidelines [here](https://gist.github.com/digitaljhelms/4287848), except use slashes in branch names instead of dashes. https://gist.github.com/digitaljhelms/4287848.
      b. Major Project Changes, such as switching to a different library, or a large refactor should have a branch
      c. Once the codebase is finalized, a comp/pre-<compname> branch is made to lock pre-comp code into a seperate branch for later viewing, if needed. post competition, a new comp/post-<compname> branch is made from the stable branch for a competition.
## Reccomended VSCode Extensions
Reccomended Extensions are included in the .code-workspace file.
Required extensions are: PROS, (C/C++ or Clangd)
