class Solution {
    public boolean isValid(char board[][],char d,int i,int j){
        //firstly checking in the particular column and particular row
        for(int k=0;k<9;k++){
            if(board[i][k]==d){
                return false;
            }
            if(board[k][j]==d){
                return false;
            }
        }

        //checking in the particular 3*3 grid
        int i_=i/3 * 3;
        int j_=j/3 * 3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[i_+k][j_+l]==d){
                    return false;
                }
            }
        }
        return true;


    }




    public boolean solve(char board[][]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    //main part
                    for(char d='1';d<='9';d++){
                        if(isValid(board,d,i,j)){
                            board[i][j]=d;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }




    public void solveSudoku(char[][] board) {
        solve(board);
    }
}