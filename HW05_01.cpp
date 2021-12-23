#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

template<typename T>
Stack<T> StackAdd(Stack<T> stack, T item)
{
    stack.Push(item);
    return stack;
}
void PrintFlag(bool flag)
{
    if (flag) cout << " Formula TRUE " << endl;
    else cout << " Formula FALSE !!! " << endl;

}
bool CheckFormula(string& formula)
{
    bool flag=true;
    Stack<char> stackTemp;
    if ((formula[0] == ')') || (formula[0] == ']') || (formula[0] == '}'))//если первой идёт закрывающаяся скобка FALSE
    {  flag = false; PrintFlag(flag);  return flag;  }
    for (size_t i = 0; formula[i] != '\0'; i++)
    {
        if((formula[i]=='(')||(formula[i]=='[')||(formula[i]=='{'))stackTemp.Push(formula[i]);//открывающаяся скобка идет в стек
        if ((formula[i] == '}'))
            if (stackTemp.GetData() == '{')stackTemp.Pop();//если открывающаяся и закрывающаяся скобки парные то идет удаление скобки из стека
            else { flag = false; PrintFlag(flag);  return flag; } //скобки не парные FALSE
        if ((formula[i] == ']'))
            if (stackTemp.GetData() == '[')stackTemp.Pop();
            else { flag = false; PrintFlag(flag);  return flag; }
        if ((formula[i] == ')'))
            if (stackTemp.GetData() == '(')stackTemp.Pop();
            else { flag = false; PrintFlag(flag);  return flag; }
    }
    if (stackTemp.GetSize()>0)flag = false;//если после прохождения цикла в стеке остались данные (скобки) FALSE
    PrintFlag(flag);
    return flag;
}

void main()
{
    string formula = "({x-y-z}*[x+2y]-(z+4x))";
    cout << formula << endl;
    CheckFormula(formula);
    string formula1 = "({x-y-z}*[x+2y]-(z+4x])";
    cout << formula1 << endl;
    CheckFormula(formula1);
    string formula2 = "){x-y-z}*[x+2y]-(z+4x))";
    cout << formula2 << endl;
    CheckFormula(formula2);
    string formula3 = "({x-y-z}*[x+2y]-(z+4x()";
    cout << formula3 << endl;
    CheckFormula(formula3);


}