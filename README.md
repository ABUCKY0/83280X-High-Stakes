<img src="blob:chrome-untrusted://media-app/f2eaff52-f90f-47ef-9e01-1bafbfa39acd" alt="LC Robotics (1280 x 640 px).png"/>![image](https://github.com/ABUCKY0/2024-High-Stakes/assets/81783950/b4a7c8b1-959e-4a4b-a0c2-f86285986757)

# 83280X High Stakes 2024 Codebase 

This project contains the team's codebase for the 2024-2025 High Stakes Season. 

# Goals

The main goals for the programming side of the robot is the following:

> As a side note, in the context of the current writing, defense is when a robot is in the scoring area of a game. This definition will be updated once the game reveal is updated, but is currently being written with Over Under in mind.  
> Defense: When a robot is on the side with their team's match load zone color and the opposing team's goal. aka, when a given team is in the opponents offsensive zone (i.e. Over Under blue team robot on the blue team's match load zone side/red team's goal side)  
> Offense: When you are on the side with your team's goal. Opposite of Defense.

- [ ] Support for Pure Pursuit through LemLib
- [ ] 2x Defensive Autonomouses
  - [ ] Main Autonomous
  - [ ] Alternate Autonomous
- [ ] 2x Offensive Autonomouses
  - [ ] Main Autonomous
  - [ ] Alternate Autonomous
- [ ] Alternate Backup Simple Auton
- [ ] 2-3x Skills Autonomouses
  - [ ] Skills1
  - [ ] Skills2
  - [ ] Skills3
- [ ] Autonomous Selector (Needs to be copied from Pre-Season Development Testing)

# Contributing Rules - [CONTRIBUTING.md](./contributing.md)

# Quality of Life Features (for the programmer)
- [ ] I'd like to have each robot subsystem split into different files, with easy interaction functions.
- [ ] Motors and Subsystems defined in a ports.hpp file, incase the build team decides to yolo where the ports plug into. 
- [ ] This code SHOULD NEVER USE COUT. It should instead use [VexLog](https://github.com/ABUCKY0/vexlog), a vex logging library. 
- [ ] Git Workflows that automatically build the code on commit, to allow for a non-programmer to just download the latest commit to test.
