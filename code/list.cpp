#include <QFile>
#include <QTextStream>
#include <QStringList>
# include <iostream>
#include <string>
# include <QString>

using namespace std;

//структура дерева
struct tree {
    int key; // содержание узла
    struct tree *left; // указатель на младшего потомка
    struct tree *right; // указатель на старшего потомка
    int h = 1; //высота
};

std::string f;

//высота
int height(tree* R) {
    if (R != NULL) return R->h;
    else return 0;
}
//разность высот левого и правого поддеревьев
int bfactor(tree* R) {
    return height(R->right) - height(R->left);
}
//восстанавливает корректное значение поля height заданного узла
void fixheight(tree* R) {
    int hl = height(R->left);
    int hr = height(R->right);
    if (hl > hr) R->h = hl + 1;
    else R->h = hr + 1;
}
// правый поворот вокруг q
tree* right_rotate(tree* p) {
    tree* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

// левый поворот вокруг p
tree* left_rotate(tree* q) {
    tree* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}
// балансировка узла
tree* balance(tree* R) {
    fixheight(R);
    if (bfactor(R) == 2) {
        if (bfactor(R->right) < 0)
            R->right = right_rotate(R->right);
        return left_rotate(R);
    }
    if (bfactor(R) == -2) {
        if (bfactor(R->left) > 0)
            R->left = left_rotate(R->left);
        return right_rotate(R);
    }
    return R; // балансировка не нужна
}
//ввод
void push(tree *&R, int val) {
    if (R == NULL) {
        R = new tree;
        R->key = val;
        R->right = NULL;
        R->left = NULL;
        return;
    }
    if (val < R->key)
        push(R->left, val);
    else
        push(R->right, val);
    R = balance(R);
}


tree *search(tree* &R, int val, int k) {
    if (val == R->key) {
        return R;
    }
    k++;
    if (val < R->key) {
        if (R->left == NULL) {
            tree *R = new tree;
            return NULL;
        }
        search(R->left, val, k);
    }
    else {
        if (R->right == NULL) {
            tree *R = new tree;
            return NULL;
        }
        search(R->right, val, k);
    }
}

tree *treemaker(std::string s)
{
    tree *root = NULL; // ячейка для корня
    std::string nn = "";
    for (int i = 0; i < s.length() + 1; i++) {
        if (s[i] != '#')
        {
            if (s[i] != ' ') {

                nn = nn + s[i];

            }
            else
            {
                int nnn = std::atoi(nn.c_str());
                if (nnn == 0 && nn != "0") return NULL;
                if (root != NULL) {
                    if (search(root, nnn, 0) != NULL) return 0;
                    else push(root, nnn);
                }
                else push(root, nnn);
                nn = "";
            }
        }
    }
    return root;
}

void print_arr(tree *R) { //версия прямого обхода
    if (R == NULL) return;
    //cout << R->key << " ";
    f = f + std::to_string(R->key) + " ";
    print_arr(R->left);
    print_arr(R->right);
}

std::string ff(tree *root)
{
    f = "";
    print_arr(root);
    return f;
}

std::string ff1(std::string start)
{
    std::string tre = "";
    tree *root = NULL;
    start = start + " #";
    root = treemaker(start);
    tre = ff(root);
    return tre;
}


QString Balan(QString str, QString REZULT)
{
    REZULT = QString::fromStdString(ff1(str.toStdString()));
    if(REZULT == QString::fromStdString(""))
        REZULT = QString::fromStdString("Ошибка ввода");
    return  REZULT;
}
