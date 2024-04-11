#pragma once
#include <iostream>
#include <vector>
#include "WorkoutDay.h"
using namespace std;

/**
 * @brief Adds a new WorkoutDay object to the vector of workout days.
 * @param day The vector of WorkoutDay pointers to add a new workout day to.
 */
void addWorkoutDay(vector<WorkoutDay*>& day);

/**
 * @brief Deletes a WorkoutDay object from the vector of workout days.
 * @param day The vector of WorkoutDay pointers to delete a workout day from.
 */
void deleteWorkoutDay(vector<WorkoutDay*>& day);

/**
 * @brief Changes the name of a WorkoutDay.
 * @param day The vector of WorkoutDay pointers to modify the name of a workout day.
 */
void ChangeNameDay(vector<WorkoutDay*>& day);

/**
 * @brief Writes the vector of WorkoutDay objects to a file.
 * @param day The vector of WorkoutDay pointers to write to a file.
 */
void writeDayToFile(vector<WorkoutDay*>& day);

/**
 * @brief Reads the vector of WorkoutDay objects from a file.
 * @param day The vector of WorkoutDay pointers to read from a file.
 */
void readDayFromFile(vector<WorkoutDay*>& day);

/**
 * @brief Displays information about WorkoutDay objects in the vector.
 * @param day The vector of WorkoutDay pointers to display information about.
 * @param str Additional string parameter for customizing display (optional).
 */
void showWorkoutDay(vector<WorkoutDay*>& day, string str = "");

/**
 * @brief Displays the main menu for interacting with WorkoutDay objects.
 * @param day The vector of WorkoutDay pointers to manage.
 */
void showMenu(vector<WorkoutDay*>& day);