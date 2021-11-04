void resuelve(stack<Accidente>& pilaAccidentes, Accidente acc)
{
    if (pilaAccidentes.empty())
        cout << "NO HAY";
    else
    {
        //Hacemos los calculos y al final del todo metemos acc en la pila
        //Basicamente hay que hacer pop hasta que encontramos al accidente con mayor numero de muertos
        //Hasta eso o hasta que la pila se quede vacia
        while (!pilaAccidentes.empty() && pilaAccidentes.top().muertos <= acc.muertos)
            pilaAccidentes.pop();

        //Si la pila se ha quedado vacia entonces NO HAY un accidente peor
        if (pilaAccidentes.empty())
            cout << "NO HAY";
        //Si no esta vacia hemos encontrado un accidente
        else
            pilaAccidentes.top().fecha.print();

    }
    //Finalmeinte, ponemos en el top el nuevo accidente
    pilaAccidentes.push(acc);
}