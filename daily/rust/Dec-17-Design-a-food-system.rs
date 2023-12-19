struct Food {
    food_rating: i32,
    food_name: String,
}

impl Food {
    fn new(food_rating: i32, food_name: String) -> Self {
        Self {
            food_rating,
            food_name,
        }
    }

    // compare food_rating
    fn cmp(&self, other: &Self) -> bool {
        if (self.food_rating == other.food_rating) {
            return self.food_name > other.food_name;
        }

        self.food_rating < other.food_rating
    }
}

struct FoodRatings {
    // map food w/rating
    food_rating_map: HashMap<String, i32>,
    // map food w/cuisine type
    food_cuisine_map: HashMap<String, String>,

    // map cuisine w/food (sort by rating/name)
    // vector element -> Food: (food_rating, food_name)
    cuisine_food_map: HashMap<String, Vec<(i32, String)>>,
}


/**
 * `&self` means the method takes an immutable reference.
 * if you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings {

    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut food_rating_map = HashMap::new();
        let mut food_cuisine_map = HashMap::new();
        let mut cuisine_food_map = HashMap::new();

        for i in 0..foods.len() {
            // store 'rating' 'cuisine' of food in food_rating_map, food_cuisine_map
            food_rating_map.insert(foods[i].clone(), ratings[i]);
            food_cuisine_map.insert(foods[i].clone(), cuisines[i].clone());
            // insert (rating, name) in cuisine_food_map
            let cuisine = cuisines[i].clone();
            cuisine_food_map.entry(cuisine).or_insert(Vec::new()).push((ratings[i], foods[i].clone()));
        }

    }

    fn change_rating(&self, food: String, new_rating: i32) {
        // update food's rating in food_rating_map
        food_rating_map.insert(food, new_rating);
        // update food's rating in cuisine_food_map
        cuisine_food_map.get_mut(food_cuisine_map.get(food)).unwrap().sort_by(|a, b| a.cmp(b));
    }

    fn highest_rated(&self, cuisine: String) -> String {
        // get highest rated food in cuisine_food_map
        let mut highest_rated = cuisine_food_map.get(cuisine).unwrap().last().unwrap().1;

        // if latest rating of food doesn't match with ratings in food vector
        // discard this food
        while food_rating_map.get(highest_rated.food_name) != highest_rated.food_rating {
            cuisine_food_map.get_mut(cuisine).unwrap().pop();
            highest_rated = cuisine_food_map.get(cuisine).unwrap().last().unwrap().1;
        }
        highest_rated.food_name
    }
}