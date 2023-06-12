# cub3d
This project is part of the 42 school curriculum.

cub3D is a minimalist implementation of the first-person shooter game Wolfenstein 3D, leveraging the power of raycasting techniques to generate a pseudo-3D gaming environment.


This project was inspired by the original game's groundbreaking usage of raycasting technology, which transformed the gaming landscape by creating an immersive first-person 3D experience on the 2D screens of the time.


cub3D seeks to take a deep dive into these foundational graphics rendering techniques, aiming to understand and recreate the process that brought these three-dimensional worlds to life.


Please note that this project is purely educational and is not intended for commercial use.

Authors:
- vmourtia: Valentin Mourtialon
- sel-maar: Sami El-Maaroufi

## Features
- 3D rendering using raycasting techniques
- Simple pathfinding algorithm for validating the input map
- Simple, intuitive controls for player movement
- Customizable maps and textures
- Collision detection

# Workflow

This project is purely academic and developed as part of the curriculum at 42 Paris. The school enforces specific coding standards and prohibits the use of certain functions and features, such as ternary operators, which may lead to code choices that might seem unconventional or less optimal.

To develop this project, we followed the following workflow:

1. **Git Branches**:
   We maintained two branches in our Git repository: `main` and `dev`. The `main` branch represents the production branch, while the `dev` branch serves as the development branch.

2. **Test-Driven Development (TDD)**:
   We employed a Test-Driven Development approach to guide our development process. This involves writing tests for each desired functionality before implementing the corresponding code. These tests were continually executed to ensure that new changes did not break existing functionality.

3. **Development Environment**:
   The `dev` branch includes a testing environment that allows us to test our project. This environment includes additional comments and code used for debugging purposes. However, this additional code is not present in the `main` branch, which represents the final code to be submitted.

4. **Incremental Development**:
   We divided the development of the project into several stages:
   - Input Validation: We verified the inputs provided to ensure they adhere to the required format and constraints.
   - Data Initialization: We set up the necessary data structures and initialized variables for further processing.
   - Input Parsing: We implemented the parsing logic to extract relevant information from the input file (.cub) and store it in appropriate data structures.
   - 3D Rendering with Raycasting: We developed the core functionality to render the 3D environment using raycasting techniques, allowing for the visualization of the game world.
   - Player Movement: We implemented the logic to handle player movements within the game world, enabling navigation through the rendered environment.

5. **Preproduction Branch**:
   Before merging changes into the `main` branch, we utilized an intermediate branch called `preproduction`. This branch served as a transitional phase, allowing us to remove any code or comments that should not be included in the final version. Once we completed this process, we pushed the changes to the `main` branch.

6. **Main Branch (Submission)**:
   The `main` branch represents the code that will be submitted to the school. On this branch, we make minimal to no changes, ensuring it reflects the final version of the project.

Please note that this workflow enabled us to work efficiently, collaborate effectively, and adhere to the guidelines and requirements set by our school while delivering a functional project.