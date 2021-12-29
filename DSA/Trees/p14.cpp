class bank{
    map<string, string> mp;

    void validate_pin();
}
class ATM: public bank{
    string bank;
    int balance;

    void dispene_cash();
    void check_balance();
    void change_pin();
    void deposit_money();
    
}