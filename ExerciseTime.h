#pragma once
#include "Exercise.h"

/**
 * @class ExerciseTime
 * @brief Represents an exercise with a duration in time, derived from the Exercise class.
 */
class ExerciseTime : public Exercise
{
private:
    int time; /**< Duration of the exercise in time units. */

public:
    /**
     * @brief Default constructor for ExerciseTime.
     */
    ExerciseTime() {};

    /**
     * @brief Parameterized constructor for ExerciseTime.
     * @param na The name of the exercise.
     * @param se The sets for the exercise.
     * @param we The weight for the exercise.
     * @param ti The duration of the exercise in time units.
     * @param ty The type of the exercise.
     */
    ExerciseTime(const string& na, int se, float we, int ti, int ty) : time(ti), Exercise(na, se, we, ty) {}

    /**
     * @brief Destructor for ExerciseTime.
     */
    ~ExerciseTime() {};

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
     * @return The duration of the exercise in time units.
     */
    int getRepsOrTime() override;

    /**
     * @brief Overrides the base class function to get information for modifying the exercise.
     */
    void getModifyInfo1() override;
};