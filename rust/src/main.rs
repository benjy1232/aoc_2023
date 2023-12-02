mod aoc_day_one;

use std::fs;

fn main() {
    let mut file_name = "resources/aoc_day1.txt";
    println!("AOC Day One");
    aoc_day_one::aoc_day_one(fs::read_to_string(file_name).expect("Unable to open aoc_day1.txt"));
}
