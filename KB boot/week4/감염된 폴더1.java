import java.util.*;

class Solution {
    public String solution(String[][] folders, String p, String q) {
        Map<String, String> parentMap = new HashMap<>();

        for (String[] folder : folders) {
            parentMap.put(folder[1], folder[0]);
        }

        Set<String> ancestors = new HashSet<>();
        String current = p;
        while (current != null) {
            ancestors.add(current);
            current = parentMap.get(current);
        }

        current = q;
        while (current != null) {
            if (ancestors.contains(current)) return current;
            current = parentMap.get(current);
         }
        return "root";
    }
}
