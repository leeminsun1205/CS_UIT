from ortools.algorithms.python import knapsack_solver
import time

def main():
    # Create the solver.
    solver = knapsack_solver.KnapsackSolver(
        knapsack_solver.SolverType.KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER,
        "KnapsackExample",
    )
    #Test cases
    path50 = 'kplib-master/12Circle/n00050/R01000/s005.kp'
    path100 = 'kplib-master/12Circle/n00100/R10000/s000.kp'
    path200 = 'kplib-master/12Circle/n00200/R01000/s017.kp'
    path500 = 'kplib-master/12Circle/n00500/R01000/s001.kp'
    path1000 = 'kplib-master/12Circle/n01000/R01000/s019.kp'
    path2000 = 'kplib-master/12Circle/n02000/R01000/s034.kp'
    path5000 = 'kplib-master/12Circle/n05000/R01000/s034.kp'
    path10000 = 'kplib-master/12Circle/n10000/R01000/s034.kp'
    paths = [path50, path100, path200, path500, path1000, path2000, path5000, path10000]
    #Iterate through the test cases
    for k in range(8):
        #Initialize the necessary parameters
        values = []
        weights = [[],]
        capacities = []
        #Read the file and add values to the parameter arrays.
        with open(paths[k], 'r') as file:
            lines = file.readlines()
            capacities.append(int(lines[2].strip()))
            for line in lines[4:]:
                value, weight = map(int, line.strip().split())
                weights[-1].append(weight)
                values.append(value)
        #Solve        
        solver.init(values, weights, capacities)
        solver.set_time_limit(180)
        start_time = time.time()
        computed_value = solver.solve()
        elapsed_time = time.time() - start_time
        print("Elapsed time:", elapsed_time, "seconds")
        #Print result
        packed_items = []
        packed_weights = []
        total_weight = 0
        print("Total value =", computed_value)
        for i in range(len(values)):
            if solver.best_solution_contains(i):
                packed_items.append(i)
                packed_weights.append(weights[0][i])
                total_weight += weights[0][i]
        print("Total weight:", total_weight)
        print("Packed items:", packed_items)
        print("Packed_weights:", packed_weights)
        #Write file
        with open('12Circle.txt', 'a') as result_file:
            result_file.write("Test case: {}\n".format(paths[k]))
            result_file.write("Run time: {} seconds\n".format(elapsed_time))
            result_file.write("Total value = {}\n".format(computed_value))
            result_file.write("Total weight = {}\n".format(total_weight))
            result_file.write("Packed items: {}\n".format(packed_items))
            result_file.write("Packed_weights: {}\n\n".format(packed_weights))

    print("Done")

if __name__ == "__main__":
    main()