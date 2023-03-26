# Finding the way out of a maze

This repository is to write a small code which helps an assasin find a way
out of a maze while he is being watched and has to evade obstacles.

## Features, rules

- A symbolizes an assasin wanting to find a way out of the maze
- F is the gate where the assasin the exit
- X are obstacles, one shall not pass them, we gotta circumvent those
- <,>,^,v characters are guards on watch, everything that falls within their line of sight acts as an obstacle.

It means that the less than sign pointing left covers the entire first line with obstacles.

Before<br />
{' ', ' ', ' ', ' ', '<'},<br />
{' ', 'X', ' ', ' ', ' '},<br />
{'A', 'X', ' ', 'X', ' '},<br />
{' ', 'X', ' ', 'X', 'F'}<br />

After<br />
{'X', 'X', 'X', 'X', 'X'},<br />
{' ', 'X', ' ', ' ', ' '},<br />
{'A', 'X', ' ', 'X', ' '},<br />
{' ', 'X', ' ', 'X', 'F'}<br />

> This is taken care by the ammendXInGrid method which checks if there is a guard at any spots and if so after determining the covered area each field to be filled gets an X resulting in e.g. the "After" grid above.

## Conditions
- Tests were taken on small datasets
- A, F, ' ', <,>,^,v characters are allowed only and expected in the output 

## Example 
Starting point <br />
{' ', ' ', ' ', 'X', ' '},<br />
{' ', 'X', ' ', ' ', ' '},<br />
{'A', 'X', ' ', 'X', ' '},<br />
{' ', ' ', ' ', '<', 'F'},<br />

Result <br />
{'.', '.', '.', 'X', ' '},<br />
{'.', 'X', '.', '.', '.'},<br />
{'A', 'X', ' ', 'X', '.'},<br />
{'X', 'X', 'X', 'X', 'F'},<br />