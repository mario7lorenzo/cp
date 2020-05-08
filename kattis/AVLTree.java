import java.util.*;

class AVLTree<T extends Comparable<T>> {
	private Node<T> root;
	private AVLTree<T> left_subtree;
	private AVLTree<T> right_subtree;
	private long left_size;
	private long right_size;
	private long height;

	public AVLTree() {
		this.root = null;
		this.height = -1;
		this.left_subtree = null;
		this.right_subtree = null;
		this.left_size = 0;
		this.right_size = 0;
	}

	private AVLTree(Node<T> root) {
		this.root = root;
		this.height = 0;
		this.left_subtree = new AVLTree<T>();
		this.right_subtree = new AVLTree<T>();
		this.left_size = 0;
		this.right_size = 0;
	}

	public AVLTree<T> insert(T value) {
		return insert(this, new Node<T>(value));
	}

	private AVLTree<T> insert(AVLTree<T> tree, Node<T> node) {
		if (tree.isEmptyTree()) {
			return new AVLTree<T>(node);
		} else if (node.compareTo(tree.getRoot()) < 0) {
			tree.left_size++;
			tree.left_subtree = insert(tree.left_subtree, node);
		} else if (node.compareTo(tree.getRoot()) > 0) {
			tree.right_size++;
			tree.right_subtree = insert(tree.right_subtree, node);
		}

		return balanceTree(tree);
	}

	public AVLTree<T> delete(T value) {
		return delete(this, new Node<T>(value));
	}

	private AVLTree<T> delete(AVLTree<T> tree, Node<T> node) {
		if (tree.isEmptyTree()) {
			return new AVLTree<T>();
		} else if (node.compareTo(tree.getRoot()) < 0) {
			tree.left_size--;
			tree.left_subtree = delete(tree.getLeftSubtree(), node);
		} else if (node.compareTo(tree.getRoot()) > 0) {
			tree.right_size--;
			tree.right_subtree = delete(tree.getRightSubtree(), node);
		} else {
			int num_of_childs = (tree.getLeftSubtree().isEmptyTree() ? 0 : 1) + (tree.getRightSubtree().isEmptyTree() ? 0 : 1);
			if (num_of_childs == 0) {
				return new AVLTree<T>();
			} else if (num_of_childs == 1) {
				return tree.getLeftSubtree().isEmptyTree()
				? tree.getRightSubtree()
				: tree.getLeftSubtree();
			} else {
				return deleteMin(tree.getRightSubtree(), tree);
			}
		}

		return balanceTree(tree);
	}

	private AVLTree<T> deleteMin(AVLTree<T> tree, AVLTree<T> main_root) {
		if (tree.getLeftSubtree().isEmptyTree()) {
			main_root.right_size--;
			main_root.right_subtree = tree.getRightSubtree();
			main_root.root = tree.getRoot();
			return balanceTree(main_root);

		} else if (tree.getLeftSubtree().getLeftSubtree().isEmptyTree()) {
			Node<T> node = tree.getLeftSubtree().getRoot();
			tree.left_size = tree.getLeftSubtree().right_size;
			tree.left_subtree = tree.getLeftSubtree().getRightSubtree();
			main_root.root = node;
			main_root.right_size--;
			return balanceTree(main_root);

		} else {
			tree.left_size--;
			return balanceTree(deleteMin(tree.getLeftSubtree(), main_root));
		}
	}

	public boolean contains(T value) {
		return !searchSubtree(this, new Node<>(value)).isEmptyTree();
	}

	private AVLTree<T> searchSubtree(AVLTree<T> tree, Node<T> node) {
		if (tree.isEmptyTree()) {
			return new AVLTree<>();
		} else if (node.compareTo(tree.getRoot()) < 0) {
			return searchSubtree(tree.getLeftSubtree(), node);
		} else if (node.compareTo(tree.getRoot()) > 0) {
			return searchSubtree(tree.getRightSubtree(), node);
		}
		return tree;
	}

	private AVLTree<T> balanceTree(AVLTree<T> tree) {
		long left_height = tree.getLeftSubtree().getHeight();
		long right_height = tree.getRightSubtree().getHeight();

		tree.height = Math.max(left_height, right_height) + 1;
		
		if (tree.getBalanceFactor() == -2) {
			if (tree.getRightSubtree().getBalanceFactor() == 1) {
				tree.right_subtree = rotateRight(tree.getRightSubtree());
			}
			tree = rotateLeft(tree);
		}

		if (tree.getBalanceFactor() == 2) {
			if (tree.getLeftSubtree().getBalanceFactor() == -1) {
				tree.left_subtree = rotateLeft(tree.getLeftSubtree());
			}
			tree = rotateRight(tree);
		}
		return tree;
	}

	private AVLTree<T> rotateLeft(AVLTree<T> tree) {
		AVLTree<T> temp = tree;
		AVLTree<T> left = tree.getLeftSubtree();
		AVLTree<T> right = tree.getRightSubtree();
		AVLTree<T> right_left = right.getLeftSubtree();
		
		tree.right_subtree = right_left;
		tree.right_size = right.left_size;
		right.left_subtree = tree;
		right.left_size += tree.left_size + 1;

		tree.height = Math.max(tree.getLeftSubtree().getHeight(), tree.getRightSubtree().getHeight()) + 1;
		right.height = Math.max(right.getLeftSubtree().getHeight(), right.getRightSubtree().getHeight()) + 1;
		return right;
	}

	private AVLTree<T> rotateRight(AVLTree<T> tree) {
		AVLTree<T> temp = tree;
		AVLTree<T> left = tree.getLeftSubtree();
		AVLTree<T> right = tree.getRightSubtree();
		AVLTree<T> left_right = left.getRightSubtree();
		
		tree.left_subtree = left_right;
		tree.left_size = left.right_size;
		left.right_subtree = tree;
		left.right_size += tree.right_size + 1;

		tree.height = Math.max(tree.getLeftSubtree().getHeight(), tree.getRightSubtree().getHeight()) + 1;
		left.height = Math.max(left.getLeftSubtree().getHeight(), left.getRightSubtree().getHeight()) + 1;
		return left;
	}

	public long getRank(T value) {
		return getRank(this, new Node<T>(value));
	}

	private long getRank(AVLTree<T> tree, Node<T> value) {
		if (tree.isEmptyTree()) {
			return 0;
		} if (value.compareTo(tree.getRoot()) < 0) {
			return getRank(tree.getLeftSubtree(), value);
		} else if (value.compareTo(tree.getRoot()) > 0) {
			return tree.getLeftSize() + 1 + getRank(tree.getRightSubtree(), value);
		}
		return tree.getLeftSize() + 1;
	}

	public long getBalanceFactor() {
		return this.getLeftSubtree().getHeight() - this.getRightSubtree().getHeight();
	}

	public long getLeftSize() {
		return this.left_size;
	}

	public long getRightSize() {
		return this.right_size;
	}

	public AVLTree<T> getLeftSubtree() {
		return this.left_subtree;
	}

	public AVLTree<T> getRightSubtree() {
		return this.right_subtree;
	}

	public Node<T> getRoot() {
		return this.root;
	}

	public boolean isEmptyTree() {
		return this.root == null;
	}

	public long getHeight() {
		return this.height;
	}

	@Override
	public String toString() {
		return "Root: " + this.root;
	}
}