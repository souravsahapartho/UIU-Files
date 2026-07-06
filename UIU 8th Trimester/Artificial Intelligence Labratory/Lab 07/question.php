import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solver;
import org.chocosolver.solver.variables.IntVar;

public class Question1 {

    public static void main(String[] args) {

        // 1. Create model
        Model model = new Model("");

        // 2. Define variables 
      

        // 3. Post adjacency constraints
                
	// 4. Solve
        Solver solver = model.getSolver();

        solver.showStatistics();

        if (solver.solve()) {
            System.out.println("Solution:");
	    /// print the value of the variables
        } else {
            System.out.println("No solution found.");
        }
    }
}