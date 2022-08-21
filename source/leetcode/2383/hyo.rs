impl Solution {
    pub fn min_number_of_hours(
        initial_energy: i32,
        initial_experience: i32,
        energy: Vec<i32>,
        experience: Vec<i32>,
    ) -> i32 {
        let mut ret = 0;
        let mut cur_energy = initial_energy;
        let mut cur_experience = initial_experience;
        for i in 0..experience.len() {
            if cur_energy <= energy[i] {
                let need = energy[i] + 1 - cur_energy;
                ret += need;
                cur_energy += need;
            }
            cur_energy -= energy[i];

            if cur_experience <= experience[i] {
                let need = experience[i] + 1 - cur_experience;
                ret += need;
                cur_experience += need;
            }
            cur_experience += experience[i];
        }

        ret
    }
}
