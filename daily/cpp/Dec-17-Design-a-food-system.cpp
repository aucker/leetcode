#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Food {
 public:
  // store food's rating
  int foodRating;
  // food's name
  string foodName;

  Food(int foodRating, string foodName) {
    this->foodRating = foodRating;
    this->foodName = foodName;
  }

  // overload operator < for comparison
  bool operator<(const Food& other) const {
    // food ratings are same sort by name
    // lexographically smaller name food will be on top
    if (foodRating == other.foodRating) return foodName > other.foodName;

    // sort on the basis of food rating
    // (bigger rating food on top)
    return foodRating < other.foodRating;
  }
};

class FoodRatings {
 private:
  // map food w/ its rating
  unordered_map<string, int> foodRatingMap;
  // map food w/ cuisine type
  unordered_map<string, string> foodCuisineMap;

  // store all food of a cuisine in priority queue (sorted by ratings/name)
  // Priority queue element -> Food: (foodRating, foodName)
  unordered_map<string, priority_queue<Food>> cuisineFoodMap;

 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    for (int i = 0; i < foods.size(); ++i) {
      // store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and
      // 'foodCuisineMap' maps
      foodRatingMap[foods[i]] = ratings[i];
      foodCuisineMap[foods[i]] = cuisines[i];
      // insert the '(rating, food)' pair in current cuisine's priority queue
      cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
    }
  }

  void changeRating(string food, int newRating) {
    // update food's rating in 'foodRatingMap'
    foodRatingMap[food] = newRating;
    // insert the '(new rating, name)' element in respective cuisine's priority
    // queue
    auto cuisineName = foodCuisineMap[food];
    cuisineFoodMap[cuisineName].push(Food(newRating, food));
  }

  string highestRated(string cuisine) {
    // get the highest rated 'food' from cuisine's priority queue
    auto highestRated = cuisineFoodMap[cuisine].top();

    // if latest rating of 'food' doesn't match with 'rating' on which it was
    // stored in priority queue discard this element of the priority queue
    while (foodRatingMap[highestRated.foodName] != highestRated.foodRating) {
      cuisineFoodMap[cuisine].pop();
      highestRated = cuisineFoodMap[cuisine].top();
    }

    // return the highest rated food
    return highestRated.foodName;
  }
};