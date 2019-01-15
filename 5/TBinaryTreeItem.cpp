#include "TBinaryTreeItem.h"

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem()
{
    item = nullptr;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(std::shared_ptr<T> obj, std::shared_ptr<TBinaryTreeItem<T>> l, std::shared_ptr<TBinaryTreeItem<T>> r, std::shared_ptr<TBinaryTreeItem<T>> p)
{
    item = obj;
    left = l;
    right = r;
    parent = p;
}

template <class T>
TBinaryTreeItem<T>::~TBinaryTreeItem()
{
}

template <class T>
std::shared_ptr<T> TBinaryTreeItem<T>::GetFigure()
{
    return this->item;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::GetNext()
{
    if (this->left) {
        return this->left;
    } else if (this->right) {
        return this->right;
    } else if (!this->parent) {
        return nullptr;
    } else {
        std::shared_ptr<TBinaryTreeItem<T>> elem;
        if (this->parent->right
        && this->parent->right->GetFigure() == this->GetFigure()) elem = this->parent->right;
        else elem = this->parent->left;
        std::shared_ptr<TBinaryTreeItem<T>> tmp = this->parent;
        while (!tmp->right || tmp->right->GetFigure() == elem->GetFigure()) {
            if (!tmp->parent) {
                return nullptr;
            }
            elem = tmp;
            tmp = tmp->parent;
        }
        return tmp->right;
    }
}

#include "figure.h"
template class TBinaryTreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TBinaryTreeItem<Figure> &obj);