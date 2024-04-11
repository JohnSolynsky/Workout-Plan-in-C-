#pragma once
#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Exercise
 * @brief Abstract base class representing an exercise with name, sets, weight, and type.
 */
class Exercise
{
protected:
    string name; /**< Name of the exercise. */
    int sets; /**< Number of sets for the exercise. */
    float weight; /**< Weight for the exercise. */
    int type; /**< Type of the exercise. */

public:
    /**
     * @brief Default constructor for Exercise.
     */
    Exercise() {};

    /**
     * @brief Parameterized constructor for Exercise.
     * @param na The name of the exercise.
     * @param se The number of sets for the exercise.
     * @param we The weight for the exercise.
     * @param ty The type of the exercise.
     */
    Exercise(const string& na, int se, float we, int ty) : sets(se), weight(we), name(na), type(ty) {}

    /**
     * @brief Virtual destructor for Exercise.
     */
    virtual ~Exercise() {};

    /**
     * @brief Pure virtual function to get information about the exercise.
     */
    virtual void getExercise() = 0;

    /**
     * @brief Pure virtual function to set the reps or time for the exercise.
     */
    virtual void setRepsOrTime() = 0;

    /**
     * @brief Pure virtual function to get the reps or time for the exercise.
     * @return The reps or time for the exercise.
     */
    virtual int getRepsOrTime() = 0;

    /**
     * @brief Pure virtual function to get information for modifying the exercise.
     */
    virtual void getModifyInfo1() = 0;

    /**
     * @brief Pure virtual function to set the reps or time for the exercise.
     * @param rt The reps or time value to set for the exercise.
     */
    virtual void setRepsOrTime(int rt) = 0;

    /**
     * @brief Setter function to set the name of the exercise.
     */
    void setName();

    /**
     * @brief Setter function to set the number of sets for the exercise.
     */
    void setSets();

    /**
     * @brief Setter function to set the weight for the exercise.
     */
    void setWeight();

    /**
     * @brief Setter function to set the name of the exercise.
     * @param n The name to set for the exercise.
     */
    void setName(string n);

    /**
     * @brief Setter function to set the number of sets for the exercise.
     * @param s The number of sets to set for the exercise.
     */
    void setSets(int s);

    /**
     * @brief Setter function to set the weight for the exercise.
     * @param w The weight to set for the exercise.
     */
    void setWeight(float w);

    /**
     * @brief Getter function to get the name of the exercise.
     * @return The name of the exercise.
     */
    string getName();

    /**
     * @brief Getter function to get the number of sets for the exercise.
     * @return The number of sets for the exercise.
     */
    int getSets();

    /**
     * @brief Getter function to get the weight for the exercise.
     * @return The weight for the exercise.
     */
    float getWeight();

    /**
     * @brief Getter function to get the type of the exercise.
     * @return The type of the exercise.
     */
    int getType();
};
