# Don-t-Wake-the-Monster-Hardware-simulation

Simulation of the game where you need to take a "treasure" from a "Monster" without being noticed

Good luck!!!

## Game Rules:
1. "Monster" is initially ASLEEP. The "treasure" is on the "Monster".
2. Player can begin the game by pressing START button.
3. Once the start button is pressed, MOVEMENT (accelerometer?) and SOUND (mic?) can wake the "Monster" up.
4. If the "Monster" is AWAKE, the "treasure" is locked or guarded.
5. If the "Monster" is AWAKE, it can turn back ASLEEP after a time delay if there is no "significant" SOUND or MOVEMENT.
6. Player wins by successfully taking the treasure from the monster.
7. ?A TIMER indicates how fast player managed to win.

## Functions

1. Start the game when the player presses the START button.
2. Detect significant sound and movement while the game is active.
3. Change the monster's state between ASLEEP and AWAKE based on sensor readings.
4. Return the monster to ASLEEP after a specified period without significant sound or movement.
5. Prevent the player from retrieving the treasure while the monster is AWAKE.
6. Detect successful treasure retrieval.
7. Measure and display the time taken to retrieve the treasure.
8. Allow the player to restart the game.

## Objectives

1. Small and compact enough to fit on a tabletop.
2. Responsive to changes in movement and sound.
3. Reliable and consistent in detecting significant sound and movement.
4. Easy to understand and operate, with clear feedback about the monster's state.
5. Affordable and feasible to build and simulate using an ESP32 and accessible electronic components.

## Constraints

1. The system must operate using an ESP32 microcontroller.
2. The system must operate within the voltage and current limits of its electronic components.
3. The system must fit within the available tabletop space.
4. The system must use components that are available or can be simulated in Wokwi.
5. The project must not take more than a month the develop.
