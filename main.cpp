#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>


#define TARGET 1000000.0

double Millionaire(int M, double P, double X);
int Input_Check(int M, double P, double X);

int main(void){
    int M;
    double P, X;

    std::cout << "Please input round number, winning probability, and the money you have: " << std::endl;

    std::cin >> M;
    std::cin >> P;
    std::cin >> X;
    
    if(Input_Check(M, P, X))
        return 0;

    std::cout << "After taking an optimal strategy, the probability of obtaining $1,000,000 is: " << std::endl;
    
    std::cout << std::fixed << std::setprecision(6) << Millionaire(M, P, X) << std::endl; 

    return 0;
}

double Millionaire(int M, double P, double X){
    int N = 1 << M;
    std::vector<double> dp, Prob_Prev, Prob_Curr;
    double Prob_Win = 0;
    double Prob_Lost = 0;
    int Curr_Money = 0, Bet_Amount = 0;
    int x_i;

    for(int i = 0; i < N+1; ++i){
        if(i < (N/2))
            dp.push_back(0);
        else if(i >= (N/2) && i < N)
            dp.push_back(P);
        else 
            dp.push_back(1);  

        Prob_Prev.push_back(dp[i]); 
        Prob_Curr.push_back(dp[i]);     
    }
    
    for(int i = 1; i < M; ++i){

        for(Curr_Money = 0; Curr_Money <= N; Curr_Money = Curr_Money + (1<<(M-i-1))){

            for(Bet_Amount = 0; Bet_Amount <= Curr_Money; Bet_Amount = Bet_Amount + (1<<(M-i-1))){
                if(Curr_Money+Bet_Amount > N)
                    break;

                Prob_Win = P * Prob_Prev[Curr_Money+Bet_Amount];
                Prob_Lost = (1-P) * Prob_Prev[Curr_Money-Bet_Amount];
                Prob_Curr[Curr_Money] = std::max(Prob_Curr[Curr_Money], Prob_Win+Prob_Lost);
            }

            dp[Curr_Money] = Prob_Curr[Curr_Money];
        
        }

        std::swap(Prob_Curr, Prob_Prev);
    }

    x_i = (int)((X/TARGET) * N);

    return dp[x_i];
}

int Input_Check(int M, double P, double X){
    int Err = 0;

    if(M > 15 || M < 1)
        Err = 1;
    
    if(P > 1.0 || P < 0.0)
        Err = 1;
    
    if(X > 1000000.0 || X < 0.0)
        Err = 1;

    if (Err)
        std::cout << "Invalid Input." << std::endl;  
    
    return Err;
}
