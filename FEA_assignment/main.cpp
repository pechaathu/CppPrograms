
#include <bits/stdc++.h>
using namespace std;

void print_the_K_inv_matrix(float K_inv[4][4])
{
    cout<<"K_inv Matrix:"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<K_inv[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}



void print_the_GSM(float K[4][4])
{
    cout<<"Global Stiffness Matrix:"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<K[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}




void print_the_ESM(float K1[2][2], float K2[2][2], float K3[2][2])
{
    cout<<"Element 1:"<<endl;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<K1[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"Element 2:"<<endl;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<K2[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"Element 3:"<<endl;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<K3[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}




void getCofactor(float A[4][4], float temp[4][4], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}




float determinant(float A[4][4], int n)
{
    float D = 0.0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
 
    float temp[4][4]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}




void adjoint(float A[4][4], float adj[4][4])
{
    int N=4;
    // temp is used to store cofactors of K[][]
    int sign = 1; float temp[4][4];
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}



void print_the_Tem(float Tem[4][1])
{
    cout<<"The Temperature matrix is:"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<1; j++)
        {
            cout<<Tem[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    
    // Getting the input values
    cout<<"Please enter the values of respective three walls"<<endl;
    cout<<"Units:"<<endl<<"T in (K)"<<endl<<"k in (W/mK)"<<endl<<"l in (m)"<<endl;
    float T1,T_inf,k1,k2,k3,l1,l2,l3,h;
    cout<<"Enter the temperature acting on the first wall:"<<endl;
    cin>>T1;
    cout<<"Enter the atmospheric temperature:"<<endl;
    cin>>T_inf;
    cout<<"Enter the convection cofficient:"<<endl;
    cin>>h;
    cout<<"Enter the thermal conductivity of first wall:"<<endl;
    cin>>k1;
    cout<<"Enter the thermal conductivity of second wall:"<<endl;
    cin>>k2;
    cout<<"Enter the thermal conductivity of third wall:"<<endl;
    cin>>k3;
    cout<<"Enter the length of first wall:"<<endl;
    cin>>l1;
    cout<<"Enter the length of second wall:"<<endl;
    cin>>l2;
    cout<<"Enter the length of third wall:"<<endl;
    cin>>l3;
    
    // Element stiffness matrix for Element (1)
    float K1[2][2];
    float K2[2][2];
    float K3[2][2];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            K1[i][j] = k1/l1;
            if(i!=j)
            {
                K1[i][j] = (-1.0)*(K1[i][j]);
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            K2[i][j] = k2/l2;
            if(i!=j)
            {
                K2[i][j] = (-1.0)*(K2[i][j]);
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            K3[i][j] = k3/l3;
            if(i!=j)
            {
                K3[i][j] = (-1.0)*(K3[i][j]);
            }
        }
    }
    
    print_the_ESM(K1, K2, K3);
    
    // Global Stiffness matrix
    float K[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            K[i][j]=0;
            if(i!=j)
            {
                if(i<=1 && j<=1)
                {
                    K[i][j] = K1[i][j];
                }
                else if(i>0 && i<=2 && j>0 && j<=2)
                {
                    K[i][j] = K2[i-1][j-1];
                }
                else if(i>1 && i<=3 && j>1 && j<=3)
                {
                    K[i][j] = K3[i-2][j-2];
                }
            }
            if(i==0 && j==0)
            {
                K[i][j] = K1[i][j];
            }
            if(i==1 && j==1)
            {
                K[i][j] = (K1[i][j])+(K2[i-1][j-1]);
            }
            if(i==2 && j==2)
            {
                K[i][j] = (K2[i-1][j-1])+(K3[i-2][j-2]);
            }
            if(i==3 && j==3)
            {
                K[i][j] = (K3[i-2][j-2])+h;
            }
        }
    }
    
    print_the_GSM(K);
    
    // Temperature matrix 4X1
    float Tem[4][1];
    float Load[4][1];
    float F_4 = h*T_inf;
    
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<1; j++)
        {
            Load[i][j] = 0;
            if(i==4 && j==0)
            {
                Load[i][j] = F_4;
            }
        }
    }
    
    
    
    
    // Matrix equation solving
    // AX=B
    // X=A(inv)B
    // K * Tem = Load
    // Tem = K(inv) * Load
    float adj[4][4];
    float K_inv[4][4];
    
    int N=4;
    
    float det = determinant(K, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        exit(0);
    }
 
    // Find adjoint
    adjoint(K, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            K_inv[i][j] = adj[i][j]/det;
        }
    }
    print_the_K_inv_matrix(K_inv);
    
    // Multiplying the K_inv and Load matrices and storing it in Tem matrix
    for(int i=0;i<4;i++)    
    {
        int j=0;
        Tem[i][j]=0;    
        for(j=0;j<4;j++)    
        {    
            Tem[i][0]+=(K_inv[i][j])*(Load[j][0]);
        }
    }
    Tem[0][0] = T1;
    
    print_the_Tem(Tem);
    
    cout<<"********** Thank You **********"<<endl;

    return 0;
}

