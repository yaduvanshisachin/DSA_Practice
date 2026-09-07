package Graph_and_dp_mix;
import java.util.*;

class State {
    int row, col, energy, mask;

    State(int row, int col, int energy, int mask) {
        this.row = row;
        this.col = col;
        this.energy = energy;
        this.mask = mask;
    }
}

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        int startRow = 0;
        int startCol = 0;
        int totalLitter = 0;

        int[][] litterNumber = new int[m][n];

        for(int[] arr : litterNumber) {
            Arrays.fill(arr, -1);
        }

        // assign id to every Littre for encoding
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                char cell = classroom[i].charAt(j);

                if(cell == 'S') {
                    startRow = i;
                    startCol = j;
                }

                if(cell == 'L') {
                    litterNumber[i][j] = totalLitter++;
                }
            }
        }

        int allCollected = (1 << totalLitter) - 1;

        Deque<State> q = new ArrayDeque<>();
        boolean vis[][][][] = 
                new boolean[m][n][energy + 1][1 << totalLitter];

        q.offer(new State(startRow, startCol, energy, 0));
        vis[startRow][startCol][energy][0] = true;

        int directions[][] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int moves = 0;

        while(!q.isEmpty()) {
            int size = q.size();

            while(size-- > 0) {
                State curr = q.poll();

                if(curr.mask == allCollected) 
                    return moves;

                // Cannot make another move
                if (curr.energy == 0) continue;

                for(int[] dir : directions) {
                    int newRow = curr.row + dir[0];
                    int newCol = curr.col + dir[1];

                    if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) {
                        continue;
                    }

                    if(classroom[newRow].charAt(newCol) == 'X') {
                        continue;
                    }

                    int newEnergy = curr.energy - 1;
                    int newMask = curr.mask;


                    char cell = classroom[newRow].charAt(newCol);
                    if(cell == 'L') {
                        int litterNumberAtCell = litterNumber[newRow][newCol];
                        newMask |= (1 << litterNumberAtCell);
                    }
                    
                    if (cell == 'R') {
                        newEnergy = energy;
                    }

                    // Already visited this exact state
                    if (vis[newRow][newCol][newEnergy][newMask]) {
                        continue;
                    }

                    vis[newRow][newCol][newEnergy][newMask] = true;
                    q.offer(new State(newRow, newCol, newEnergy, newMask)); 
                }
            }

            moves++;
        }
        return -1;
    }
}

public class Leetcode3568 {
    
}
