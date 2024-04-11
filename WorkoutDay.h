#pragma once
#include "Exercise.h"
#include <vector>
#include <fstream>

/**
 * @class WorkoutDay
 * @brief Represents a workout day with a name and a list of exercises.
 */
class WorkoutDay
{
private:
    string name; /**< Name of the workout day. */
    vector<Exercise*> exercise; /**< List of exercises for the workout day. */

public:
    /**
     * @brief Default constructor for WorkoutDay.
     */
    WorkoutDay() {};

    /**
     * @brief Parameterized constructor for WorkoutDay.
     * @param na The name of the workout day.
     */
    WorkoutDay(const string& na) : name(na) {}

    /**
     * @brief Destructor for WorkoutDay.
     */
    ~WorkoutDay() {};

    /**
     * @brief Getter function to retrieve the name of the workout day.
     * @return The name of the workout day.
     */
    string getDayName();

    /**
     * @brief Setter function to set the name of the workout day.
     */
    void setDayName();

    /**
     * @brief Setter function to set the name of the workout day.
     * @param na The name to set for the workout day.
     */
    void setDayName(const string& na);

    /**
     * @brief Displays a menu for interacting with the WorkoutDay object.
     */
    void menu();

    /**
     * @brief Adds an exercise to the list of exercises.
     * @param exercise The vector of Exercise pointers to add an exercise to.
     */
    void addExercise(vector<Exercise*>& exercise);

    /**
     * @brief Deletes an exercise from the list of exercises.
     * @param exercise The vector of Exercise pointers to delete an exercise from.
     */
    void deleteExercise(vector<Exercise*>& exercise);

    /**
     * @brief Modifies an existing exercise in the list of exercises.
     * @param exercise The vector of Exercise pointers to modify an exercise in.
     */
    void modifyExercise(vector<Exercise*>& exercise);

    /**
     * @brief Writes the list of exercises to a file.
     * @param file The file stream to write to.
     */
    void writeExerciseToFile(fstream& file);

    /**
     * @brief Reads the list of exercises from a file.
     * @param file The file stream to read from.
     */
    void readExerciseFromFile(fstream& file);
};