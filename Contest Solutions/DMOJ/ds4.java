import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int n = scanner.nextInt(), m = scanner.nextInt(), ans = 0, v;
		char op;
		Tree tree = new Tree();
	    	for (int i = 0; i < n; i++) tree.insert(scanner.nextInt());
	    	while (m-- > 0) {
	    		op = scanner.next().charAt(0);
	    		v = scanner.nextInt() ^ ans;
	    		if (op == 'I') tree.insert(v);
	    		else if (op == 'R') tree.delete(v);
	    		else if (op == 'S') {
	    			ans = tree.smallest(v);
	    			System.out.println(ans);
	    		}
	    		else {
	    			ans = tree.index(v);
	    			System.out.println(ans);
	    		}
	    	}
	    	tree.inorder(tree.root);
	    	System.out.println();
	}
}

class Tree {
	Node root = null;
	int bruh = 0;
	public void insert(int value) {
		root = insert(value, root);
	}
	public Node insert(int value, Node temp) {
		if (temp == null) return new Node(value);
		if (value == temp.value) temp.count++;
		else if (value > temp.value) temp.right = insert(value, temp.right);
		else temp.left = insert(value, temp.left);
		update(temp);
		return balance(temp);
	}
	public void delete(int value) {
		root = delete(value, root, 1);
	}
	public Node delete(int value, Node temp, int amt) {
		if (temp == null) return null;
		if (value != temp.value) {
			if (value > temp.value) temp.right = delete(value, temp.right, amt);
			else temp.left = delete(value, temp.left, amt);
		}
		else {
			temp.count -= amt;
			temp.size -= amt;
			if (temp.count > 0) return temp;
			if (temp.left == null) return temp.right;
			else if (temp.right == null) return temp.left;
			Node min = getMin(temp.right);
			temp.value = min.value;
			temp.count = min.count;
			temp.right = delete(temp.value, temp.right, temp.count);
		}
		update(temp);
		return balance(temp);
	}
	public Node getMin(Node node) {
		while (node.left != null) node = node.left;
		return node;
	}
	public void update(Node temp) {
		int lh = -1, rh = -1;
		temp.size = temp.count;
		if (temp.left != null) {
			lh = temp.left.height;
			temp.size += temp.left.size;
		}
		if (temp.right != null) {
			rh = temp.right.height;
			temp.size += temp.right.size;
		}
		temp.height = 1 + Math.max(lh, rh);
		temp.bf = rh - lh;
	}
	public Node balance(Node temp) {
		if (temp.bf == -2) {
			if (temp.left.bf > 0) temp.left = leftRotate(temp.left);
			temp = rightRotate(temp);
		}
		else if (temp.bf == 2) {
			if (temp.right.bf < 0) temp.right = rightRotate(temp.right);
			temp = leftRotate(temp);
		}
		return temp;
	}
	public Node leftRotate(Node temp) {
		Node right = temp.right;
		temp.right = right.left;
		right.left = temp;
		update(temp);
		update(right);
		return right;
	}
	public Node rightRotate(Node temp) {
		Node left = temp.left;
		temp.left = left.right;
		left.right = temp;
		update(temp);
		update(left);
		return left;
	}
	public int smallest(int v) {
		return smallest(v, root, 0);
	}
	public int smallest(int v, Node temp, int l) {
		if (l + (temp.left == null ? 0 : temp.left.size) + 1 > v) return smallest(v, temp.left, l);
		else if (l + (temp.left == null ? 0 : temp.left.size) + temp.count < v) return smallest(v, temp.right, l + temp.count + (temp.left == null ? 0 : temp.left.size));
		return temp.value;
	}
	public int index(int v) {
		return index(v, root, 0);
	}
	public int index(int v, Node temp, int l) {
		if (temp == null) return -1;
		if (v < temp.value) return index(v, temp.left, l);
		if (v > temp.value) return index(v, temp.right, l + temp.count + (temp.left == null ? 0 : temp.left.size));
		return l + (temp.left == null ? 0 : temp.left.size) + 1;
	}
	public void inorder(Node temp) {
		if (temp == null) return;
		if (temp.left != null) inorder(temp.left);
		for (int i = 0; i < temp.count; i++, bruh++) System.out.print(bruh == 0 ? temp.value : " " + temp.value);
		if (temp.right != null) inorder(temp.right);
	}
}

class Node {
	int value, height = 0, bf = 0, size = 1, count = 1;
	Node left = null, right = null;
	public Node(int value) {
		this.value = value;
	}
}
