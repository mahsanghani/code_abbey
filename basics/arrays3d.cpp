//
// Created by Ahsan Ghani on 2022-06-30.
//
#include <iostream>

int main(){
    int packages [] [4] {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {3,4,5,6}
    };
    for(size_t i{0} ; i < 3; ++ i){
        for(size_t j{0}; j < 4 ; ++j){
            std::cout << packages[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    for(size_t i{0} ; i < std::size(packages); ++ i){
        for(size_t j{0}; j < std::size(packages[i])  ; ++j){
            std::cout << packages[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    //3D arrays are defined in the same way. We just use three sets of indexes
    // 3 lights per room, 5 rooms per house 7 houses per block
    int house_block [7] [5] [3] {
            {
                    {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}
            },
            {
                    {16,17,18},{19,20,21},{22,23,24},{25,26,27},{28,29,30}
            },
            {
                    { 31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45}
            },
            {
                    {46,47,48},{49,50,51},{52,53,54},{55,56,57},{58,59,60}
            },
            {
                    {61,62,63},{64,65,66},{67,68,69},{70,71,72},{73,74,75}
            },
            {
                    {76,77,78},{79,80,81},{82,83,84},{85,86,87},{88,89,90}
            },
            {
                    {91,92,93},{94,95,96},{97,98,99},{100,101,102},{103,104,105}
            }
    };
    for(size_t i{0}; i < std::size(house_block) ; ++i){

        for(size_t j{0} ; j < std::size(house_block[i]) ; ++j){

            for(size_t k{0} ; k < std::size(house_block[i][j]) ; ++k){

                std::cout << house_block[i][j][k] << "     ";
            }
        }
    }
    const size_t num_cols{3};

    int packages2 [] [5] {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {10,11,12},
            {100,110,120} // Can add as many triplets in packages2 as we want
    };

    std::cout << std::endl;
    std::cout << "Ommiting leftmost dimension for 2d array : " << std::endl;
    for (size_t i{0} ; i < std::size(packages2) ; ++i){
        for( size_t j{0} ; j < std::size(packages2[i]) ; ++j){
            std::cout << "Item (" << i << "," << j << ") : " << packages2[i][j] << std::endl;
        }
    }
    int house_block1 [] [5] [3] {

            {
                    {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}
            },
            {
                    {16,17,18},{19,20,21},{22,23,24},{25,26,27},{28,29,30}
            },
            {
                    { 31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45}
            },
            {
                    {46,47,48},{49,50,51},{52,53,54},{55,56,57},{58,59,60}
            }

    };
    for (size_t i {0} ; i < std::size(house_block1 ); ++i){

        for( size_t j{0}; j < std::size(house_block1[i]) ; ++j){

            std::cout << "[";
            for( size_t k{0}; k < std::size(house_block1[i][j]) ; ++k){

                std::cout << house_block1[i][j][k] << " ";
            }
            std::cout <<"] " ;//Separate elements for good visualization
        }
        std::cout << std::endl;//Separate elements for good visualization
    }
    int house_block2 [] [5] [4] { 	// Try to make the last dimension 5 and show
            //that the compiler appends 2 zeros
            {
                    {1,2,3},{4},{7,8,9},{10,11,12},{13,14,15}  //The one element array will be autofilled
                    // with zeros to complete 4 elements
            },
            {
                    {16,17,18},{19,20,21},{22,23,24},{25,26,27},{28,29,30}
            },
            {
                    { 31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45}
            },
            {
                    {46,47,48},{49,50,51},{52,53,54},{55,56,57}//,{58,59,60}  // The spots for {58,59,60
                    // Will be autofilled with 0
            }

    };
    //Modify data
    house_block2[0][2][1] = 1021;
    std::cout << std::endl;
    std::cout << "Printing out 3d house_block array with defaulted elements : " << std::endl;
    for (size_t i {0} ; i < std::size(house_block2 ); ++i){
        for( size_t j{0}; j < std::size(house_block2[i]) ; ++j){
            std::cout << "[";
            for( size_t k{0}; k < std::size(house_block2[i][j]) ; ++k){
                std::cout << house_block2[i][j][k] << " ";
            }
            std::cout <<"] " ;//Separate elements for good visualization
        }
        std::cout << std::endl;//Separate elements for good visualization
    }
    return 0;
}