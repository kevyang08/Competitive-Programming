import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    char op = scanner.next().toUpperCase().charAt(0);
    int x;
    BinarySearchTree tree = new BinarySearchTree();
    
    while (op != 'E') {
      if (op == 'I') {
        x = scanner.nextInt();
        tree.add(x);
      }
      else if (op == 'R') {
        x = scanner.nextInt();
        tree.remove(x);
      }
      else if (op == 'F') {
        x = scanner.nextInt();
        System.out.println(tree.contains(x));
      }
      else if (op == 'P') {
        tree.traverse();
        System.out.println();
      }
      op = scanner.next().toUpperCase().charAt(0);
    }
    tree.traverse();
    System.out.println();
  }
}

class Node {
  int value;
  Node left, right;
  public Node(int value) {
    this.value = value;
    left = right = null;
  }
}

class BinarySearchTree {
  Node root;
  public BinarySearchTree() {
    root = null;
  }
  public void add(int value) {
    root = addNode(value, root);
  }
  public void remove(int value) {
    root = deleteNode(value, root);
  }
  public void traverse() {
    traverseNodes(root);
  }
  public boolean contains(int value) {
    return nodeContains(value, root);
  }
  private Node addNode(int value, Node node) {
    if (node == null) {
      return new Node(value);
    }
    else if (value > node.value) {
      node.right = addNode(value, node.right);
    }
    else {
      node.left = addNode(value, node.left);
    }
    return node;
  }
  private Node deleteNode(int value, Node node) {
    if (node == null) {
      return null;
    }
    else if (node.value == value) {
      if (node.left == null) {
        return node.right;
      }
      else if (node.right == null) {
        return node.left;
      }
      if (getDepth(node.left) > getDepth(node.right)) {
        node.value = getMax(node.left);
        node.left = deleteNode(node.value, node.left);
      }
      else {
        node.value = getMin(node.right);
        node.right = deleteNode(node.value, node.right);
      }
    }
    else if (value > node.value) {
      node.right = deleteNode(value, node.right);
    }
    else {
      node.left = deleteNode(value, node.left);
    }
    return node;
  }
  private void traverseNodes(Node node) {
    if (node != null) {
      traverseNodes(node.left);
      System.out.print(node.value + " ");
      traverseNodes(node.right);
    }
  }
  private boolean nodeContains(int value, Node node) {
    if (node == null) {
      return false;
    }
    else if (node.value == value) {
      return true;
    }
    return value > node.value ? nodeContains(value, node.right) : nodeContains(value, node.left);
  }
  private int getDepth(Node node) {
    if (node == null) {
      return 0;
    }
    return Math.max(getDepth(node.left), getDepth(node.right)) + 1;
  }
  private int getMin(Node node) {
    while (node.left != null) {
      node = node.left;
    }
    return node.value;
  }
  private int getMax(Node node) {
    while (node.right != null) {
      node = node.right;
    }
    return node.value;
  }
  private Node getNode(int index, Node node) {
    if (node == null) {
      return null;
    }
    else if (node.value == index) {
      return node;
    }
    return index > node.value ? getNode(index, node.right) : getNode(index, node.left);
  }
}
