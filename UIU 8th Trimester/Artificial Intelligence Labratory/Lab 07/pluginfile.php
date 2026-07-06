import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solver;
import org.chocosolver.solver.variables.IntVar;

public class MapColoring {

public static void main(String[] args) {

// 1. Create model
Model model = new Model("Map Coloring Problem");

// 2. Define variables (regions with domain 1..3)
IntVar WA = model.intVar("WA", 1, 3);
IntVar NT = model.intVar("NT", 1, 3);
IntVar SA = model.intVar("SA", 1, 3);
IntVar Q = model.intVar("Q", 1, 3);
IntVar NSW = model.intVar("NSW", 1, 3);
IntVar V = model.intVar("V", 1, 3);
IntVar T = model.intVar("T", 1, 3); // independent

// 3. Post adjacency constraints (neighboring regions must differ)

model.arithm(WA, "!=", NT).post();
model.arithm(WA, "!=", SA).post();

model.arithm(NT, "!=", SA).post();
model.arithm(NT, "!=", Q).post();

model.arithm(SA, "!=", Q).post();
model.arithm(SA, "!=", NSW).post();
model.arithm(SA, "!=", V).post();

model.arithm(Q, "!=", NSW).post();

model.arithm(NSW, "!=", V).post();

// Tasmania (T) has no neighbors → no constraints

// 4. Solve
Solver solver = model.getSolver();

solver.showStatistics();

if (solver.solve()) {
System.out.println("Solution:");
System.out.println("WA = " + WA.getValue());
System.out.println("NT = " + NT.getValue());
System.out.println("SA = " + SA.getValue());
System.out.println("Q = " + Q.getValue());
System.out.println("NSW = " + NSW.getValue());
System.out.println("V = " + V.getValue());
System.out.println("T = " + T.getValue());
} else {
System.out.println("No solution found.");
}
}
}