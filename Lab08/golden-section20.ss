#lang racket
;golden-section20
(define a 3)
(define b 5);2.32415
(define (fun x)

(set! x (+ x (-(/ 27 28))))
(+ (+ x (sin(+ (* 2 x) (-(/ pi 4)))) (log (+ x 1))) (- (/ 1 2))) )

(define (golden-section-search a b)
 (let(
      (xmin(cond((<= a b)(golden-start a b))(else (golden-start b a ))))
     )
     (newline)
     xmin
 )
)
(define (golden-start a b)
 (let(
      (xa (+ a (* mphi (+ b (- a)))))
      (xb (+ b ( - (* mphi(+ b (- a))))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)

(define (set1 a b xa xb ya yb)
  (set! b xb)
  (set! xb xa)
  (set! yb ya)
  (set! xa (+ a (* mphi(+ b (- a)))))
  (try a b xa (fun xa) xb yb)
 )
(define (set2 a b xa xb ya yb)
  (set! a xa)
  (set! xa xb)
  (set! ya yb)
  (set! xb (+ b (-(* mphi(+ b (- a))))))
  (try a b xa ya xb (fun xb))
 )
(define mphi (/ (+ 3(- (sqrt 5))) 2))
(define (try a b xa ya xb yb)
 (cond((close-enough? a b)
      (/ (+ a b) 2))
      (else(let() (display "+")
             (cond((<= ya yb)(set1 a b xa xb ya yb))
                  (else(set2 a b xa xb ya yb))

             );cond...
      );let...
 ));if...
)
(define (close-enough? x y)
  (<= (abs (+ x (- y)))tolerance))
(define tolerance (/ 1 100000))
(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)