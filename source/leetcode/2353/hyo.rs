use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::collections::HashMap;

#[derive(Clone, Eq, PartialEq)]
struct Food {
    name: String,
    rating: i32,
}

impl Food {
    fn new(name: String, rating: i32) -> Self {
        Self { name, rating }
    }
}

impl Ord for Food {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.rating > other.rating {
            Ordering::Greater
        } else if self.rating == other.rating {
            if self.name < other.name {
                Ordering::Greater
            } else if self.name == other.name {
                Ordering::Equal
            } else {
                Ordering::Less
            }
        } else {
            Ordering::Less
        }
    }
}

impl PartialOrd for Food {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct FoodRatings {
    rating_map: HashMap<String, i32>,
    cuisine_map: HashMap<String, String>,
    heap_map: HashMap<String, BinaryHeap<Food>>,
}

impl FoodRatings {
    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let n = foods.len();
        let mut rating_map = HashMap::new();
        let mut cuisine_map = HashMap::new();
        let mut heap_map = HashMap::new();
        for i in 0..n {
            rating_map.insert(foods[i].clone(), ratings[i]);
            cuisine_map.insert(foods[i].clone(), cuisines[i].clone());
            let e = heap_map
                .entry(cuisines[i].clone())
                .or_insert(BinaryHeap::new());

            e.push(Food::new(foods[i].clone(), ratings[i]));
        }

        Self {
            rating_map,
            cuisine_map,
            heap_map,
        }
    }

    fn change_rating(&mut self, food: String, new_rating: i32) {
        self.rating_map.insert(food.clone(), new_rating);
        let cuisine = self.cuisine_map.get(&food).unwrap();
        self.heap_map
            .entry(cuisine.clone())
            .and_modify(|e| e.push(Food::new(food, new_rating)));
    }

    fn highest_rated(&mut self, cuisine: String) -> String {
        let heap = self.heap_map.entry(cuisine.clone()).or_default();
        loop {
            let Food { name, rating } = heap.peek().unwrap();
            if rating != self.rating_map.get(name).unwrap() {
                heap.pop();
            } else {
                break;
            }
        }

        heap.peek().unwrap().name.clone()
    }
}
