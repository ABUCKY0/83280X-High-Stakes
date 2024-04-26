# Contributing Guidelines

1. All Code should follow Google's Style Guide (Some things I don't know and dont' care to remember, i'm specifically referring to using 2 spaces for code instead of 4, and similar rules.)
2. All Code should be clear, concise, and documented. All functions need doxygen, and if something appears ambigious, such as a for loop without a clear purpose, it should have comments.
   1. Extending the above, everything should have clear variable names. This means Labeling Motors A,B,C..., and naming motors MOTOR_A-DRIVETRAIN, or MOTOR_G-LAUNCHER.
   2. Loops should be avoided in main functions, excluding while loops to keep a function running. This means no looping over data inside of opcontrol()


## Reccomended VSCode Extensions
Reccomended Extensions are included in the .code-workspace file.
Required extensions are: PROS, (C/C++ or Clangd)