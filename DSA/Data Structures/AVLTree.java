import java.util.*;
import java.io.*;

public class AVL {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		AVLTree tree = new AVLTree();
	    char op = scanner.next().charAt(0);
	    while (op != 'e') {
	    	int x;
	        if (op == 'a') {
	        	x = scanner.nextInt();
	        	tree.insert(x);
	        }
	        else if (op == 'd') {
	        	x = scanner.nextInt();
	        	tree.delete(x);
	        }
	        else if (op == 'p') {
	        	tree.preorder(tree.root);
	          	System.out.println();
	        }
	        else if (op == 'i') {
	        	tree.inorder(tree.root);
	        	System.out.println();
	        }
	        else if (op == 'P') {
	        	tree.postorder(tree.root);
	        	System.out.println();
	        }
	        op = scanner.next().charAt(0);
	    }
	}
}


class AVLTree {
	Node root = null;
	public void insert(int value) {
		root = insert(value, root);
	}
	public Node insert(int value, Node temp) {
		if (temp == null) return new Node(value);
		if (value > temp.value) temp.right = insert(value, temp.right);
		else if (value < temp.value) temp.left = insert(value, temp.left);
		update(temp);
		return balance(temp);
	}
	public void delete(int value) {
		root = delete(value, root);
	}
	public Node delete(int value, Node temp) {
		if (temp == null) return null;
		if (value != temp.value) {
			if (value > temp.value) temp.right = delete(value, temp.right);
			else temp.left = delete(value, temp.left);
		}
		else {
			if (temp.left == null) return temp.right;
			else if (temp.right == null) return temp.left;
			temp.value = getMin(temp.right);
			temp.right = delete(temp.value, temp.right);
		}
		update(temp);
		return balance(temp);
	}
	public int getMin(Node node) {
		while (node.left != null) node = node.left;
		return node.value;
	}
	public int getMax(Node node) {
		while (node.right != null) node = node.right;
		return node.value;
	}
	public void update(Node temp) {
		int lh = -1, rh = -1;
		if (temp.left != null) lh = temp.left.height;
		if (temp.right != null) rh = temp.right.height;
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
	public void preorder(Node temp) {
		if (temp == null) return;
		System.out.print(temp.value + " ");
		if (temp.left != null) preorder(temp.left);
		if (temp.right != null) preorder(temp.right);
	}
	public void inorder(Node temp) {
		if (temp == null) return;
		if (temp.left != null) inorder(temp.left);
		System.out.print(temp.value + " ");
		if (temp.right != null) inorder(temp.right);
	}
	public void postorder(Node temp) {
		if (temp == null) return;
		if (temp.left != null) postorder(temp.left);
		if (temp.right != null) postorder(temp.right);
		System.out.print(temp.value + " ");
	}
}

class Node {
  int value, height = 0, bf = 0;
  Node left = null, right = null;
  public Node(int value) {
    this.value = value;
  }
}
