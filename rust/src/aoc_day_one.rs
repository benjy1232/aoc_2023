use std::collections::HashMap;

pub fn aoc_day_one(input: String) {
    let lines = input
        .split('\n')
        .filter(|x| !x.is_empty())
        .collect::<Vec<&str>>();
    part_one(lines.clone());
    part_two(lines);
}

fn part_one(lines: Vec<&str>) {
    let mut sum: i32 = 0;
    for line in lines {
        let nums = line
            .chars()
            .collect::<Vec<char>>()
            .iter()
            .filter(|x| x.is_digit(10))
            .map(|x| x.to_digit(10).unwrap() as i32)
            .collect::<Vec<i32>>();
        if nums.len() != 0 {
            sum += nums.first().unwrap() * 10 + nums.last().unwrap();
        }
    }
    println!("Sum: {}", sum);
}

fn part_two(lines: Vec<&str>) {
    let mut sum: i32 = 0;
    let nums = [
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];
    let nums_map = HashMap::from([
        ("one", 1),
        ("two", 2),
        ("three", 3),
        ("four", 4),
        ("five", 5),
        ("six", 6),
        ("seven", 7),
        ("eight", 8),
        ("nine", 9),
    ]);
    for line in lines {
        let l = line.to_lowercase();
        let mut first_idx: usize = std::usize::MAX;
        let mut last_idx: usize = 0;
        let mut first_val = 0;
        let mut last_val = 0;
        for num in nums {
            let mut v: Vec<usize> = l
                .match_indices(num)
                .collect::<Vec<(usize, &str)>>()
                .iter()
                .map(|(i, _)| *i)
                .collect();
            if v.len() == 0 {
                continue;
            }
            v.sort();
            let i = v.first().unwrap();
            let j = v.last().unwrap();

            if *i <= first_idx {
                first_val = nums_map[num];
                first_idx = *i;
            }
            if *j >= last_idx {
                last_val = nums_map[num];
                last_idx = *j;
            }
        }
        for (i, c) in line.chars().enumerate() {
            if c.is_digit(10) {
                let j = usize::from(i);
                if i < first_idx {
                    first_idx = i;
                    first_val = c.to_digit(10).unwrap() as i32;
                }
                if j >= last_idx {
                    last_idx = i;
                    last_val = c.to_digit(10).unwrap() as i32;
                }
            }
        }
        sum += first_val * 10 + last_val;
    }
    println!("Sum: {}", sum);
}
