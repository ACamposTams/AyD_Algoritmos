struct Nodo
{
    int valor;
    Nodo* left;
    Nodo* right;
    
    Nodo(int n) 
    {
        valor = n;
        left = right = nullptr;
    }

    void destroy() 
    {
        if (this) 
        {
            destroy(this->left);
            destroy(this->right);
            delete this;
        }
    }

    void destroy(Nodo* nodo)
    {
        if (nodo) 
        {
            destroy(nodo->left);
            destroy(nodo->right);
            delete nodo;
        }
    }
};
