import java.util.*;

class Solution {
    List<Set<Integer>> candidateKeys = new ArrayList<>();

    public int solution(String[][] relation) {
        int colSize = relation[0].length;
        int rowSize = relation.length;

        for (int i = 1; i < (1 << colSize); i++) {
            Set<String> tuples = new HashSet<>();

            for (int row = 0; row < rowSize; row++) {
                StringBuilder sb = new StringBuilder();
                for (int col = 0; col < colSize; col++) {
                    if ((i & (1 << col)) != 0) {
                        sb.append(relation[row][col]).append(",");
                    }
                }
                tuples.add(sb.toString());
            }

            if (tuples.size() == rowSize && isMinimal(i)) {
                candidateKeys.add(convertToSet(i, colSize));
            }
        }

        return candidateKeys.size();
    }

    private boolean isMinimal(int bitmask) {
        for (Set<Integer> key : candidateKeys) {
            boolean isSubset = true;
            for (int idx : key) {
                if ((bitmask & (1 << idx)) == 0) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) return false;
        }
        return true;
    }

    private Set<Integer> convertToSet(int bitmask, int colSize) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < colSize; i++) {
            if ((bitmask & (1 << i)) != 0) set.add(i);
        }
        return set;
    }
}
