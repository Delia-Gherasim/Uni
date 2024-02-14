;For a given tree of type (1) return the path from the root node to a certain given node X.

(defun from_n(n lst)
    (cond
        ((= n 0) lst)
        ((null lst) lst)
        (t(from_n(- n 1)(cdr lst)))))
        
(defun find_path (tree target)
  (cond
   ((null tree) nil)
   ((eql (car tree) target) (list target))
   ((numberp (cadr tree))
    (let ((left_path (find_path (cddr tree) target)))
      (if left_path
          (cons (car tree) left_path)
          (let ((right_path (find_path (from_n(1+ (cadr tree)) tree) target)))
            (if right_path
                (cons (car tree) right_path)
                nil)))))
   (t (let ((subtree (find_path (cadr tree) target)))
        (if subtree
            (cons (car tree) subtree)
            nil)))))

(setq tree1 '(A 2 B 0 C 2 D 0 E 0))
(print (find-path-type-1 tree1 'C)) 