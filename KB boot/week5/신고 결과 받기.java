import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        Map<String, Set<String>> reporterMap = new HashMap<>();
        Map<String, Integer> reportedCount = new HashMap<>();
        
        for (String rep : report) {
            String[] parts = rep.split(" ");
            String reporter = parts[0];
            String reported = parts[1];
            
            reporterMap.putIfAbsent(reporter, new HashSet<>());
            
            if (reporterMap.get(reporter).add(reported)) {
                reportedCount.put(reported, reportedCount.getOrDefault(reported, 0) + 1);
            }
        }
        
        Set<String> bannedUsers = new HashSet<>();
        for (String user : id_list) {
            if (reportedCount.getOrDefault(user, 0) >= k) {
                bannedUsers.add(user);
            }
        }
        
        int[] answer = new int[id_list.length];
        Map<String, Integer> idIndexMap = new HashMap<>();
        for (int i = 0; i < id_list.length; i++) {
            idIndexMap.put(id_list[i], i);
        }
        
        for (String reporter : reporterMap.keySet()) {
            for (String target : reporterMap.get(reporter)) {
                if (bannedUsers.contains(target)) {
                    int idx = idIndexMap.get(reporter);
                    answer[idx]++;
                }
            }
        }
        return answer;
    }
}
