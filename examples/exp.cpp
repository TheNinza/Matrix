#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object to remove the rows and columns which cannot be converted to double.
The sliced Matrix object is then converted to double and then the exp() method is applied to it.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    Matrix exp_mat = matrix.exp(sliced_mat);

    exp_mat.print();

    return 0;
}