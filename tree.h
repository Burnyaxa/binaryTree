#include <iostream>
#include <ctime>
using namespace std;

struct element {
	int data, h;
	element *left, *right;
	element(int value = 0) {
		this->data = value;
		this->h = 1;
		this->left = 0;
		this->right = 0;
	}
};

struct tree{
	element *top;
	tree(){
		top = new element();
		this->top = 0;
	}
	int height(element *el){
		return el ? el->h : 0;
	}
	int balance_factor(element *el){
		return height(el->right) - height(el->left);
	}
	void calc_height(element *el){
		int h_left = this->height(el->left);
		int h_right = this->height(el->right);
		el->h = (h_left>h_right ? h_left : h_right) + 1;
	}
	element *left_rotate(element *l){
		element *r = new element();
		r = l->right;
		l->right = r->left;
		r->left = l;
		this->calc_height(l);
		this->calc_height(r);

		return r;
	}
	element *right_rotate(element *r){
		element *l = new element();
		l = r->left;
		r->left = l->right;
		l->right = r;

		this->calc_height(l);
		this->calc_height(r);

		return l;
	}
	element *balancing(element *el){
		this->calc_height(el);
		if (this->balance_factor(el) == 2){
			if (this->balance_factor(el->right)<0) el->right = this->right_rotate(el->right);
			el = this->left_rotate(el);
			return el;
		}
		else if (this->balance_factor(el) == -2) {
			if (this->balance_factor(el->left)>0) el->left = this->left_rotate(el->left);
			el = this->right_rotate(el);
			return el;
		}
		return el;
	}
	element *ins(element *el, int data){
		if (!el) return new element(data);
		if (data < el->data) el->left = this->ins(el->left, data);
		else el->right = this->ins(el->right, data);
		return this->balancing(el);
	}
	void add(int data){
		this->top = this->ins(this->top, data);
	}
	element *find_left(element *el){
		return el->left ? this->find_left(el->left) : el;
	}
	element *removemin(element *el){
		if (el->left == 0) return el->right;
		el->left = this->removemin(el->left);
		return this->balancing(el);
	}
	element *remove(element *el, int data){
		if (!el) return 0;
		if (data<el->data) el->left = this->remove(el->left, data);
		else if (data>el->data) el->right = this->remove(el->right, data);
		else{
			element *q = new element();
			q = el->left;
			//console.log("q");
			//this.postfix(q);
			element *r = new element();
			r = el->right;
			el = 0;
			if (!r) return q;
			element *min = new element();
			min = this->find_left(r);
			min->right = this->removemin(r);
			min->left = q;
			return this->balancing(min);
		}
		return this->balancing(el);
	}
	void del(int data){
		this->top = this->remove(this->top, data);
	}
	bool find(int data){
		element *p = new element();
		p = this->top;
		while (p){
			if (data<p->data) p = p->left;
			else if (data>p->data) p = p->right;
			else if (p->data == data) return true;
		}
		return false;
	}
	void postfix(element *top){
		if (top == 0) return;
		this->postfix(top->left);
		this->postfix(top->right);
		cout << top->data << " ";
	}
	void prefix(element *top){
		if (top == 0) return;
		cout << top->data << " ";
		this->prefix(top->left);
		this->prefix(top->right);
	}
	void infix(element *top){
		if (!top) return;
		this->infix(top->left);
		cout << top->data << " ";
		this->infix(top->right);
	}
};