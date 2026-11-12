#include <stdio.h>

void displayPacks()
{
    printf("\n===== MOBILE RECHARGE =====\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

int getPack()
{
    int pack;

    do
    {
        printf("Enter pack number (1-4): ");
        scanf("%d", &pack);
    }
    while (pack < 1 || pack > 4);

    return pack;
}

long long getMobile()
{
    long long mobile;

    do
    {
        printf("Enter 11-digit mobile number: ");
        scanf("%lld", &mobile);
    }
    while (mobile < 10000000000LL || mobile > 99999999999LL);

    return mobile;
}

int findAmount(int pack)
{
    switch (pack)
    {
        case 1: return 100;
        case 2: return 200;
        case 3: return 500;
        case 4: return 1000;
    }

    return 0;
}

double calculateTax(double amount)
{
    return amount * 0.15;
}

double calculateBonus(double amount)
{
    if (amount >= 500)
        return amount * 0.10;
    else
        return 0;
}

void printSlip(long long mobile, double amount,
               double tax, double balance)
{
    printf("\n===== RECHARGE SLIP =====\n");
    printf("Mobile Number: %lld\n", mobile);
    printf("Recharge Amount: Rs. %.2lf\n", amount);
    printf("Tax (15%%): Rs. %.2lf\n", tax);
    printf("Total Balance: Rs. %.2lf\n", balance);
    printf("=========================\n");
}

int main()
{
    double totalSpent = 0;

    for (int i = 1; i <= 3; i++)
    {
        printf("\nRecharge %d\n", i);

        displayPacks();

        int pack = getPack();
        long long mobile = getMobile();

        double amount = findAmount(pack);
        double tax = calculateTax(amount);
        double bonus = calculateBonus(amount);

        double balance = amount + bonus;

        printSlip(mobile, amount, tax, balance);

        totalSpent = totalSpent + amount + tax;
    }

    printf("\nTotal Money Spent: Rs. %.2lf\n", totalSpent);

    return 0;
}