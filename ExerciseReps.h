#pragma once
#include "Exercise.h"

/**
 * @class ExerciseReps
 * @brief Represents an exercise with a specified number of repetitions, derived from the Exercise class.
 */
class ExerciseReps : public Exercise
{
private:
    int reps; /**< Number of repetitions for the exercise. */

public:
    /**
     * @brief Default constructor for ExerciseReps.
     */
    ExerciseReps() {};

    /**
     * @brief Parameterized constructor for ExerciseReps.
     * @param na The name of the exercise.
     * @param se The sets for the exercise.
     * @param we The weight for the exercise.
     * @param re The number of repetitions for the exercise.
     * @param ty The type of the exercise.
     */
    ExerciseReps(const string& na, int se, float we, int re, int ty) : reps(re), Exercise(na, se, we, ty) {}

    /**
     * @brief Destructor for ExerciseReps.
     */
    ~ExerciseReps() {};

    /**
     * @brief Overrides the base class function to display information about the exercise.
     */
    void getExercise() override;

    /**
     * @brief Overrides the base class function to set the reps or time for the exercise.
     */
    void setRepsOrTime() override;

    /**
     * @brief Overrides the base class function to set the reps or time for the exercise.
     * @param rt The reps or time value to set for the exercise.
     */
    void setRepsOrTime(int rt) override;

    /**
     * @brief Overrides the base class function to get the reps or time for the exercise.
     * @return The number of repetitions for the exercise.
     */
    int getRepsOrTime() override;

    /**
     * @brief Overrides the base class function to get information for modifying the exercise.
     */
    void getModifyInfo1() override;
};
