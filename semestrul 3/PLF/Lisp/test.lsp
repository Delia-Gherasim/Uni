; problem 1:  map as walk 
; double the numerical values in a list at any level 
; test:  
; > (double '(1 2 a (3 4) b c))  
; (2 4 A (6 8) B C) 
(defun problem1 (lst)
    (cond
        ((null lst)0)
        ((numberp lst) (* 2 lst))
        ((atom lst) lst)
        (t(mapcar #'problem1 lst )) ))
(print(problem1 '(1 2 a (3 4) b c)))  


; problem 4: workers 
; given a list of length n of sublists representing work items and a list of length n of functions representing workers obtain the list of results of performing the work 
; by each worker on their corresponding work item 
; test: 
; > (work '(+ * -) '((2 3) (1 2) (7 5 1))) 
; (5 2 1) 
(defun problem2 (l1 l2)
  (cond
    ((null l1) nil)
    ((null l2) nil)
    (t (mapcar #'apply l1 l2)) ))
(print(problem2 '(+ * -) '((2 3) (1 2) (7 5 1)))) 