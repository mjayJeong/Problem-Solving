import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> map = new HashMap();
        
        for (String player : participant) {
            if (map.containsKey(player)) {
                map.put(player, map.get(player) + 1);
            } else {
                map.put(player, 1);
            }
        }
        
        for (String player : completion) {
            map.put(player, map.get(player) - 1);
        }
        
        for (String player : map.keySet()) {
            if (map.get(player) != 0) {
                return player;
            }
        }
        
        return "";
    }
}
