#define CATCH_CONFIG_MAIN
#include "enums.hpp"
#include "defs.hpp"
#include "face.hpp"
#include "cubie.hpp"
#include "cube.hpp"
#include "catch.hpp"
#include <iostream>
#include <chrono>

TEST_CASE("solved_cube") {
	Cube cb, cb_reference;
	REQUIRE(cb == cb_reference);
}

TEST_CASE("demonstration") {
	Cube cb;
	cb.Randomize();
	std::vector<Move> solution = cb.Solve();
	std::cout << "Algorythm's performance example.\n";
	std::cout << "Random cube:\n" << cb << "Solution string: " << solution << "\nSolution's length: " << solution.size() << " moves\n";
	uint32_t counter = 1;
	for (auto i : solution) {
		cb.Multiply(i);
		std::cout << "\n" << counter << ". " << i << ":\n" << cb;
		++counter;
	}
	std::cout << "Cube solved.";
}

TEST_CASE("random_cubes") {
	Cube cb_reference;
	Cube cb_max_min;
	cb_max_min.Randomize();
	size_t solution_max = cb_max_min.Solve().size(), solution_min = cb_max_min.Solve().size();
	float average_size = 0;
	size_t N = 1000;
	float average_interval1 = 0, average_interval2 = 0, average_interval3 = 0;
	for (int32_t i = 0; i < N; ++i) {
		Cube cb;
		std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
		cb.Randomize();
		std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
		std::vector<Move> solution = cb.Solve();
		std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
		cb.Multiply(solution);
		std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
		average_size += solution.size();
		average_interval1 += std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count();
		average_interval2 += std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count();
		average_interval3 += std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3).count();
		if (solution.size() < solution_min) {
			solution_min = solution.size();
		}
		if (solution.size() > solution_max) {
			solution_max = solution.size();
		}
		REQUIRE(cb == cb_reference);
	}
	average_size /= N;
	average_interval1 /= N;
	average_interval2 /= N;
	average_interval3 /= N;
	std::cout << "\n\n\n\n\nAlgorythm's average performance.\n";
	std::cout << "Number of cubes: " << N << "\nAverage solution length: " << average_size
		<< " moves\nAverage cube randomization time: " << average_interval1 << " microseconds\nAverage solution time: " << average_interval2
		<< " microseconds\nAverage solution verification time: " << average_interval3
		<< " microseconds\nShortest solution: " << solution_min << " moves\nLongest solution: " << solution_max << " moves\n";
}