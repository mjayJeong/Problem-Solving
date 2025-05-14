import java.util.*;

class Solution {
    static class Node {
        int id, people;
        Node left, right;
        Node(int id, int people) {
            this.id = id;
            this.people = people;
        }
    }

    int groupCount;

    public int solution(int k, int[] num, int[][] links) {
        int n = num.length;
        Node[] nodes = new Node[n];
        boolean[] hasParent = new boolean[n];

        for (int i = 0; i < n; i++) nodes[i] = new Node(i, num[i]);
        for (int i = 0; i < n; i++) {
            int left = links[i][0];
            int right = links[i][1];
            if (left != -1) {
                nodes[i].left = nodes[left];
                hasParent[left] = true;
            }
            if (right != -1) {
                nodes[i].right = nodes[right];
                hasParent[right] = true;
            }
        }

        int root = 0;
        for (int i = 0; i < n; i++) {
            if (!hasParent[i]) {
                root = i;
                break;
            }
        }

        int left = Arrays.stream(num).max().getAsInt();
        int right = Arrays.stream(num).sum();
        int answer = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            groupCount = 1; 
            if (dfs(nodes[root], mid) <= mid && groupCount <= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    private int dfs(Node node, int limit) {
        if (node == null) return 0;

        int left = dfs(node.left, limit);
        int right = dfs(node.right, limit);

        if (left + right + node.people <= limit) {
            return left + right + node.people;
        } else if (Math.min(left, right) + node.people <= limit) {
            groupCount++;
            return Math.min(left, right) + node.people;
        } else {
            groupCount += 2;
            return node.people;
        }
    }
}
